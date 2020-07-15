#ifndef LZ78_H
#define LZ78_H
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>
using namespace std;

typedef basic_string<unsigned char> ustring;

class LZ78
{
public:
    LZ78(string src,string dest);
    void comp();
    void uncomp();
private:
    string src;
    string dest;
    ustring decToBin(const int& x) const;
    int binToDec(const unsigned char& x) const;
    ustring stringToASCII(const ustring& x) const;
    char ASCIIToChar(const ustring& x) const;
    ustring fileRead(const string filename);
    void fileWrite(const string  filename, const ustring x);
    void fileWriteBin(const string filename, const ustring x);
};

#endif // LZ78_H
