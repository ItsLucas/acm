#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct HTNode {
    unsigned char ch;
    unsigned int weight,parent,lchild,rchild;
};

struct HTree {
    HTNode data[512];
    int root;
};

class Huffman
{
public:
    Huffman(string filename);
    void comp();
    void uncomp();
private:
    bool oneChar=false;
    bool emptyFile=false;
    char *thr[256];
    string fileName;
    HTree T;
    unsigned int charNum[256];
    void getCharNum();
    int getWeight(int &a,int &b);
    void createTree();
    void createHuffmanCode();
    unsigned int _comp();
    void _uncomp();
    //char* strrev(char* s);
    ofstream fout;
    ifstream fin;
};

#endif // HUFFMAN_H
