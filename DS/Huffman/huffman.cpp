#include "huffman.h"
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
Huffman::Huffman(string filename)
{
    fileName=filename;
    memset(charNum,0,sizeof(charNum));
    fin.open(filename.c_str(),ios_base::in|ios_base::binary);
}

void Huffman::getCharNum() {
    fin.seekg(0,fin.beg);
    unsigned char buffer;
    while(1) {
        buffer=fin.get();
        if(fin.eof()) break;
        charNum[buffer]++;
    }
}
std::vector<std::string> split(std::string str,std::string pattern)
{
  std::string::size_type pos;
  std::vector<std::string> result;
  str+=pattern;
  auto size=str.size();

  for(unsigned long long i=0; i<size; i++)
  {
    pos=str.find(pattern,i);
    if(pos<size)
    {
      std::string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+pattern.size()-1;
    }
  }
  return result;
}

int Huffman::getWeight(int &a, int &b) {
    a=0;
    b=0;
    int i = 1;
    for(;i<=511&&T.data[i].weight;i++) {
        if(!T.data[i].parent) {
            a=i;
            break;
        }
    }
    for(i++;i<=511&&T.data[i].weight;i++) {
        if(!T.data[i].parent) {
            b=i;
            break;
        }
    }
    if(!b) {
        T.root=a;
        return 0;
    }
    for(i++;i<=511&&T.data[i].weight;i++){
        if(!T.data[i].parent&&T.data[i].weight<T.data[a].weight)
            a=i;
        else if(!T.data[i].parent&&T.data[i].weight<T.data[b].weight)
            b=i;
    }
    return i;
}

void Huffman::createTree() {
    memset(T.data,0,sizeof(T.data));
    int j=1,a,b,pos,nnum=0;
    for(int i=0;i<=255;i++){
        if(charNum[i]==0)continue;
        nnum++;
        T.data[j].rchild=T.data[j].lchild=T.data[j].parent=0;
        T.data[j].weight=charNum[i];
        T.data[j++].ch=i;
    }
    if(nnum==0)    {    emptyFile=true;    return;}
    else if(nnum==1){    oneChar=true;    return;}
    while((pos=getWeight(a,b))){
        T.data[pos].lchild=a;
        T.data[pos].rchild=b;
        T.data[pos].parent=0;
        T.data[pos].weight=T.data[a].weight+T.data[b].weight;
        T.data[a].parent=T.data[b].parent=pos;
    }
}

void Huffman::createHuffmanCode(){
    if(emptyFile==true||oneChar==true)return;
    for(int i=1;!T.data[i].lchild;i++){
        unsigned int j=i,p=0;
        char temp[300]={0};
        while(T.data[j].parent){
            temp[p++]=(T.data[T.data[j].parent].rchild==j)+'0';
            j=T.data[j].parent;
        }
        thr[T.data[i].ch]=(char*)malloc(sizeof(char)*(p+1));
        strcpy(thr[T.data[i].ch],strrev(temp));
    }
}

unsigned int Huffman::_comp() {
    fin.close();
    fin.open(fileName.c_str(),ios_base::in|ios_base::binary);
    char temp[300]={0},temp2[9]={0};
    int zerocnt = 0;
    ofstream fout;
    stringstream ss;
    ss<<fileName<<".hz";
    fout.open(ss.str(),ios_base::out|ios_base::binary);
    if(oneChar) {
        unsigned char ch;
        ch=fin.get();
        fin.seekg(0,fin.end);
        fout<<0<<fin.tellg()<<ch;
        fout.close();
        return 6;
    }
    fout.put(1);
    for(auto x:charNum) {
        fout.write(reinterpret_cast<char*>(&x),sizeof(unsigned int));
    }
    fin.close();
    fin.open(fileName.c_str(),ios_base::in|ios_base::binary);
    unsigned char ch;
    int l = 0;
    while(!fin.eof()) {
        ch=fin.get();
        if(fin.eof()) {
            zerocnt=strlen(temp);
            strcat(temp,"00000000");
        }
        else strcat(temp,thr[ch]);
        l=strlen(temp);
        while((l-=8)>0) {
            strncpy(temp2,temp,8);
            unsigned char tm=strtol(temp2,NULL,2);
            fout.put(tm);
            strcpy(temp,temp+8);
        }
    }
    fout<<8-zerocnt;
    fout.close();
    return 0;
}

void Huffman::comp() {
    getCharNum();
    createTree();
    createHuffmanCode();
    _comp();
}

void Huffman::_uncomp() {
    fin.close();
    fin.open(fileName.c_str(),ios_base::in|ios_base::binary);
    fin.seekg(-1,fin.end);
    unsigned int end = fin.tellg();
    end++;
    unsigned char zc = fin.get();
    fin.close();
    fin.open(fileName.c_str(),ios_base::in|ios_base::binary);
    unsigned char ch;
    ofstream fout;
    vector<string> s = split(fileName,".");
    stringstream ss;
    ss<<s[0];
    ss<<".";
    ss<<s[1];
    fout.open(ss.str(),ios_base::out|ios_base::binary);
    int k=8;
    ch=fin.get();
    for(int i=0;i<256;i++) {
        fin.read(reinterpret_cast<char*>(&charNum[i]),sizeof(unsigned int));
    }
    createTree();
    int p=T.root;
    ch=fin.get();
    if(fin.tellg()!=end)
    while(1) {
        while(k&&T.data[p].rchild) {
            if((ch>>--k)&1) {
                p=T.data[p].rchild;
            }
            else {
                p=T.data[p].lchild;
            }
        }
        if(!k) {
            ch=fin.get();
            k=8;
            if(fin.tellg()==end) break;
        }
        else{
            fout.put(T.data[p].ch);
            p=T.root;
        }
    }
    do {
        while(k>zc&&T.data[p].rchild) {
            if((ch>>--k)&1) {
                p=T.data[p].rchild;
            }
            else {
                p=T.data[p].lchild;
            }
        }
        fout.put(T.data[p].ch);
        p=T.root;
    }while(k>zc);
    fin.close();
    fout.close();
}

void Huffman::uncomp() {
    char c;
    fin.close();
    fin.open(fileName.c_str(),ios_base::in|ios_base::binary);
    c=fin.get();
    if(c==0) {
        ofstream fout;
        vector<string> s = split(fileName,".");
        stringstream ss;
        ss<<s[0];
        ss<<".";
        ss<<s[1];
        fout.open(ss.str(),ios_base::out|ios_base::binary);
        unsigned int end;
        fin>>end>>c;
        while(end--) {
            fout.put(c);
        }
        fin.close();
        fout.close();
        return;
    }
    _uncomp();
}
