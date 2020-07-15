#include "libio.h"
#include "lzw.h"
#include <cassert>
#include <ctime>
#include <iostream>

typedef unsigned long long ull;
typedef unsigned char byte;
unsigned getLzwMap(const std::vector<byte> &input, byte *lzwMap) {
    const ull size = input.size();
    bool used[256];
    for (unsigned i = 0; i < 256; ++i) {
        used[i] = false;
        lzwMap[i] = 255;
    }

    for (ull i = 0; i < size; ++i)
        used[input[i]] = true;

    unsigned lzwMapCount = 0;
    for (unsigned i = 0; i < 256; ++i) {
        if (used[i])
            lzwMap[i] = lzwMapCount++;
    }
    return lzwMapCount;
}

unsigned rb(unsigned value) {
    unsigned bits = 1;
    while ((value >>= 1) > 0)
        ++bits;
    return bits;
}

struct _string {
    unsigned prefixidx;
    unsigned first;
    unsigned nextLeft, nextRight;
    byte k;
    _string(byte newByte = 0, unsigned pI = ~0U)
        : prefixidx(pI), first(~0U), nextLeft(~0U), nextRight(~0U),
          k(newByte) {}
};

class dict {
    std::vector<_string> seq;
    unsigned dictStart, new_stringidx;
    std::vector<byte> decoded;
    unsigned add(_string &c) {
        if (c.prefixidx == ~0U)
            return c.k;

        unsigned index = seq[c.prefixidx].first;
        if (index == ~0U)
            seq[c.prefixidx].first = new_stringidx;
        else {
            while (true) {
                if (c.k == seq[index].k)
                    return index;
                if (c.k < seq[index].k) {
                    const unsigned next = seq[index].nextLeft;
                    if (next == ~0U) {
                        seq[index].nextLeft = new_stringidx;
                        break;
                    }
                    index = next;
                } else {
                    const unsigned next = seq[index].nextRight;
                    if (next == ~0U) {
                        seq[index].nextRight = new_stringidx;
                        break;
                    }
                    index = next;
                }
            }
        }
        seq[new_stringidx++] = c;

        return ~0U;
    }

    void filldecoded(unsigned code) {
        decoded.clear();
        while (code != ~0U) {
            const _string &cs = seq[code];
            decoded.push_back(cs.k);
            code = cs.prefixidx;
        }
    }

  public:
    dict(unsigned mb, unsigned dictStart)
        : seq(1 << mb), dictStart(dictStart),
          new_stringidx(dictStart) {
        for (unsigned i = 0; i < dictStart; ++i)
            seq[i].k = i;
    }

    bool search_string(_string &c) {
        unsigned index = add(c);
        if (index != ~0U) {
            c.prefixidx = index;
            return true;
        }
        return false;
    }

    void decode(unsigned oldCode, unsigned code, std::vector<byte> &outStream,
                const byte *lzwMap) {
        const bool exists = code < new_stringidx;

        if (exists)
            filldecoded(code);
        else
            filldecoded(oldCode);

        for (ull i = decoded.size(); i > 0;)
            outStream.push_back(lzwMap[decoded[--i]]);
        if (!exists)
            outStream.push_back(lzwMap[decoded.back()]);

        seq[new_stringidx].prefixidx = oldCode;
        seq[new_stringidx++].k = decoded.back();
    }

    unsigned size() const { return new_stringidx; }

    void reset() {
        new_stringidx = dictStart;
        for (unsigned i = 0; i < dictStart; ++i)
            seq[i] = _string(i);
    }
};
/*
 *  dict.init(size:256)
    prefix.clear()
    b=input.next
    if(dict.exist(prefix+B))
        prefix=prefix+b
    else
        dict.add(prefix+b)
    write(prefix.idx,result)
    prefix=b
    if(!input.empty)
    goto b.input.next
    else write(prefix.idx,result)
*/
void LZWCodec::encode(const std::vector<unsigned char> &input, std::vector<unsigned char> &encoded) {
    unsigned int mb = 24;
    const ull size = input.size();
    encoded.clear();
    encoded.reserve(size + size / 8);

    byte lzwMap[256];
    const unsigned lzwMapSize = getLzwMap(input, lzwMap);
    const bool mapped = lzwMapSize < 256;
    const unsigned eoiCode = lzwMapSize;
    const unsigned dictStart = lzwMapSize + 1;
    const unsigned minBits = rb(dictStart);
    if (mb < minBits)
        mb = minBits;

    encoded.push_back(byte(mb));
    encoded.push_back(byte(lzwMapSize));
    if (mapped)
        for (unsigned i = 0; i < 256; ++i)
            if (lzwMap[i] < 255)
                encoded.push_back(byte(i));

    dict dict(mb, dictStart);
    StreamWriter writer(encoded);
    _string currentString;
    unsigned currentBits = minBits;
    unsigned nextBitIncLimit = (1 << minBits) - 1;

    for (ull i = 0; i < size; ++i) {
        currentString.k = lzwMap[input[i]];
        if (!dict.search_string(currentString)) {
            writer.write(currentString.prefixidx, currentBits);
            currentString.prefixidx = currentString.k;

            if (dict.size() == nextBitIncLimit) {
                if (currentBits == mb) {
                    currentBits = minBits;
                    dict.reset();
                } else
                    ++currentBits;
                nextBitIncLimit = (1 << currentBits) - 1;
            }
        }
    }

    writer.write(currentString.prefixidx, currentBits);
    if (dict.size() == nextBitIncLimit - 1)
        ++currentBits;
    writer.write(eoiCode, currentBits);
}

/*
 *  dict.init(size:256)
    idx=first;
    write(idx,result)
    oldidx=idx
    idx=idx->next
    if(idx.exist)
        write(idx,result)
        B=index.getfirstBit()
        dict.add(old+b)
    else
        B=oldidx.getfirstBit()
        dict.add(old+b)
        write(old+b,result)
    old=index
    goto idx=idx->next
*/
void LZWCodec::decode(const std::vector<byte> &encoded,
                      std::vector<byte> &decoded) {
    decoded.clear();

    byte lzwMap[256];
    const unsigned mb = encoded[0];
    const unsigned lzwMapSize = (encoded[1] == 0 ? 256 : encoded[1]);
    const unsigned eoiCode = lzwMapSize;
    const unsigned dictStart = lzwMapSize + 1;
    const unsigned minBits = rb(dictStart);

    if (lzwMapSize < 256)
        for (unsigned i = 0; i < lzwMapSize; ++i)
            lzwMap[i] = encoded[i + 2];
    else
        for (unsigned i = 0; i < 256; ++i)
            lzwMap[i] = byte(i);

    dict dict(mb, dictStart);
    StreamReader reader(encoded, encoded[1] == 0 ? 2 : 2 + lzwMapSize);

    while (true) {
        dict.reset();
        unsigned currentBits = minBits;
        unsigned nextBitIncLimit = (1 << minBits) - 2;

        unsigned code = reader.read(currentBits);
        if (code == eoiCode)
            return;
        decoded.push_back(lzwMap[code]);
        unsigned oldCode = code;

        while (true) {
            code = reader.read(currentBits);
            if (code == eoiCode)
                return;

            dict.decode(oldCode, code, decoded, lzwMap);
            if (dict.size() == nextBitIncLimit) {
                if (currentBits == mb)
                    break;
                else
                    ++currentBits;
                nextBitIncLimit = (1 << currentBits) - 2;
            }

            oldCode = code;
        }
    }
}
