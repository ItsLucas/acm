#include "lz78.h"

LZ78::LZ78(string src,string dest) {
    this->src=src;
    this->dest=dest;
}

void LZ78::comp() {
    map<ustring,int> dict;
    ustring chars;
    ustring codes;
    ustring ch;
    ustring pre;
    chars=fileRead(src);
    for(auto i=0;i<chars.length();i++) {
        ch=chars.substr(i,1);
        if(dict.count(pre+ch)) {
            pre+=ch;
        }
        else {
            if(pre.empty()) {
                ustring s;
                for(int j=1;j<=8;j++) {
                    s.push_back('0');
                }
                codes+=s;
            }
            else {
                codes+=decToBin(dict[pre]);
            }
            codes+=stringToASCII(ch);
            dict[pre+ch]=dict.size()+1;
            pre.clear();
        }
    }
    fileWriteBin(dest,codes);
}

void LZ78::uncomp() {
    map<int,ustring> dict;
    ustring chars;
    ustring codes;
    ustring ch;
    int cw;
    codes=fileRead(src);
    for(auto i=0;i<codes.length();i+=2) {
        cw=binToDec(codes[i]);
        ch=codes.substr(i+1,1);
        if (cw!=0)
            chars+=dict[cw];
        chars+=ch;
        if(cw!=0)
            dict[dict.size()+1]=dict[cw]+ch;
        else
            dict[dict.size()+1]=ch;
    }
    fileWrite(dest,chars);
}

ustring LZ78::decToBin(const int& x) const
{
    bitset<8> bs(x);
    string s = bs.to_string();
    ustring ret;
    for(auto x:s) {
        ret.push_back((unsigned char)x);
    }
    return ret;
}

int LZ78::binToDec(const unsigned char& x) const
{
    bitset<8> dec(x);
    return dec.to_ulong();
}

ustring LZ78::stringToASCII(const ustring& x) const
{
    bitset<8> bs(x[0]);
    string s = bs.to_string();
    ustring ret;
    for(auto x:s) {
        ret.push_back((unsigned char)x);
    }
    return ret;
}

char LZ78::ASCIIToChar(const ustring& x) const
{
    return (unsigned char)bitset<8>(x).to_ulong();
}

ustring LZ78::fileRead(const string filename)
{
    ifstream t(filename,ios_base::binary);
    unsigned char ch;
    ustring s;
    while(!t.eof()) {
        ch=t.get();
        s.push_back(ch);
    }
    return s;
}

void LZ78::fileWrite(const string filename, const ustring x)
{
    ofstream out(filename);
    for(auto i:x) {
        out.put(i);
    }
    out.close();
}

void LZ78::fileWriteBin(const string filename, const ustring x)
{
    ustring buffer;
    long temp;
    unsigned char output;
    ofstream out(filename);

    for (int i = 0; i < x.length(); i += 8)
    {
        buffer = x.substr(i, 8);
        temp = strtol(reinterpret_cast<const char*>(buffer.c_str()),0, 2);
        output = temp & 0xffl;
        out << output;
    }

    out.close();
}


