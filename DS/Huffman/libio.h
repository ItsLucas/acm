/**
 * StreamIO Library
 *
 * Required minimal compiler version is GCC 4.7.
 *
 * Copyright (C) 2007 Juha Nieminen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LIBIO_H
#define LIBIO_H

#include <vector>

class StreamWriter {
    typedef unsigned char byte;
    std::vector<byte> &stream;
    unsigned curBitIndex;

  public:
    inline StreamWriter(std::vector<byte> &s);

    inline void write(unsigned value, unsigned bits);
};

class StreamReader {
    typedef unsigned char byte;
    const std::vector<byte> &stream;
    unsigned curBitIndex;
    size_t curByteIndex;

  public:
    inline StreamReader(const std::vector<byte> &s, size_t startIndex);

    inline unsigned read(unsigned bits);
};

inline StreamWriter::StreamWriter(std::vector<byte> &s)
    : stream(s), curBitIndex(0) {}

inline void StreamWriter::write(unsigned value, unsigned bits) {
    while (bits > 0) {
        if (curBitIndex == 0) {
            stream.push_back(byte(value));
            if (bits < 8) {
                curBitIndex += bits;
                bits = 0;
            } else {
                bits -= 8;
                value >>= 8;
            }
        } else {
            const byte b = byte(value << curBitIndex);
            stream.back() |= b;
            const unsigned bitsWritten = 8 - curBitIndex;
            if (bits < bitsWritten) {
                curBitIndex += bits;
                bits = 0;
            } else {
                bits -= bitsWritten;
                value >>= bitsWritten;
                curBitIndex = 0;
            }
        }
    }
}

inline StreamReader::StreamReader(const std::vector<byte> &s, size_t startIndex)
    : stream(s), curBitIndex(0), curByteIndex(startIndex) {}

inline unsigned StreamReader::read(unsigned bits) {
    unsigned res = 0;
    unsigned resBitIndex = 0;

    while (bits > 0) {
        unsigned iValue = stream[curByteIndex];

        if (curBitIndex == 0) {
            if (bits < 8) {
                const unsigned mask = ~(~0U << bits);
                res |= (iValue & mask) << resBitIndex;
                curBitIndex += bits;
                bits = 0;
            } else {
                res |= iValue << resBitIndex;
                resBitIndex += 8;
                bits -= 8;
                ++curByteIndex;
            }
        } else {
            const unsigned mask = ~(~0U << bits);
            res |= ((iValue >> curBitIndex) & mask) << resBitIndex;
            const unsigned bitsLeft = 8 - curBitIndex;
            if (bits < bitsLeft) {
                curBitIndex += bits;
                bits = 0;
            } else {
                curBitIndex = 0;
                ++curByteIndex;
                bits -= bitsLeft;
                resBitIndex += bitsLeft;
            }
        }
    }

    return res;
}

#endif
