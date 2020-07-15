#include "huffmanwindow.h"
#include "ui_huffmanwindow.h"
#include <QFileDialog>
#include <iostream>
#include "lpk.h"
#include "huffman.h"
#include <fstream>
#include <sstream>
#include "lzw.h"
#include <QMessageBox>
using namespace std;

HuffmanWindow::HuffmanWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HuffmanWindow)
{
    ui->setupUi(this);
}

HuffmanWindow::~HuffmanWindow()
{
    delete ui;
}


void HuffmanWindow::on_pushButton_clicked()
{
    //QStringList fn = QFileDialog::getOpenFileNames(this,tr("Open File"),"./",tr("All files (*.*)"));
    QString fn = QFileDialog::getExistingDirectory(this,tr("Open File"),"./");
    if(fn==nullptr) return;
    QStringList list = fn.split("/");
    lpk l(fn,list.last()+".lpk");
    l.commit();
    Huffman huffman(list.last().toStdString()+".lpk");
    huffman.comp();
    QFile filetemp(list.last()+".lpk");
    filetemp.remove();
    QMessageBox::information(NULL,"Huffman","Done");
}

std::vector<std::string> split2(std::string str,std::string pattern)
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

void HuffmanWindow::on_pushButton_2_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File"),"./",tr("HuffmanZip(*.hz)"));
    if(fn==nullptr) return;
    if(!fn.contains(".hz")) return;
    Huffman huffman(fn.toStdString());
    huffman.uncomp();
    if(!fn.contains(".lpk")) return;
    QStringList list = fn.split(".");
    QString lpkt=list.at(0)+"."+list.at(1);
    lpk l(lpkt);
    l.unpack();
    QFile filetemp(list.last()+".lpk");
    filetemp.remove();
    QMessageBox::information(NULL,"Huffman","Done");
}

void HuffmanWindow::on_pushButton_5_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File"),"./");
    if(fn==nullptr) return;
    Huffman huffman(fn.toStdString());
    huffman.comp();
    QMessageBox::information(NULL,"Huffman","Done");
}

void HuffmanWindow::on_pushButton_6_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File"),"./");
    if(fn==nullptr) return;
    ifstream fin;
    fin.open(fn.toStdString(),ios_base::binary);
    vector<unsigned char> stream1;
    vector<unsigned char> result;
    while(!fin.eof())
    stream1.push_back(fin.get());
    lzw lzw;
    lzw.encode(stream1,result);
    ofstream fout;
    fin.close();
    fout.open((fn+".lzw").toStdString(),ios_base::binary);
    for(auto x:result) {
        fout.put(x);
    }
    fout.close();
    QMessageBox::information(NULL,"Huffman","Done");
}

void HuffmanWindow::on_pushButton_4_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File"),"./",tr("LZW(*.lzw)"));
    if(fn==nullptr) return;
    if(!fn.contains(".lzw")) return;
    vector<string> s = split2(fn.toStdString(),".");
    stringstream ss;
    ss<<s[0];
    ss<<".";
    ss<<s[1];
    ifstream fin;
    fin.open(fn.toStdString(),ios_base::binary);
    vector<unsigned char> stream1;
    vector<unsigned char> result;
    while(!fin.eof())
    stream1.push_back(fin.get());
    lzw lzw;
    lzw.decode(stream1,result);
    ofstream fout;
    fin.close();
    fout.open(ss.str(),ios_base::binary);
    for(auto x:result) {
        fout.put(x);
    }
    fout.close();
    if(!fn.contains(".lpk")) return;
    QStringList list = fn.split(".");
    QString lpkt=list.at(0)+"."+list.at(1);
    lpk l(lpkt);
    l.unpack();
    QFile filetemp(list.last()+".lpk");
    filetemp.remove();
    QMessageBox::information(NULL,"Huffman","Done");
}

void HuffmanWindow::on_pushButton_3_clicked()
{
    QString fn = QFileDialog::getExistingDirectory(this,tr("Open File"),"./");
    if(fn==nullptr) return;
    QStringList list = fn.split("/");
    lpk l(fn,list.last()+".lpk");
    l.commit();
    ifstream fin;
    fin.open(list.last().toStdString()+".lpk",ios_base::binary);
    vector<unsigned char> stream1;
    vector<unsigned char> result;
    while(!fin.eof())
    stream1.push_back(fin.get());
    lzw lzw;
    lzw.encode(stream1,result);
    ofstream fout;
    fin.close();
    fout.open(list.last().toStdString()+".lpk"+".lzw",ios_base::binary);
    for(auto x:result) {
        fout.put(x);
    }
    fout.close();
    QFile filetemp(list.last()+".lpk");
    filetemp.remove();
    QMessageBox::information(NULL,"Huffman","Done");
}
