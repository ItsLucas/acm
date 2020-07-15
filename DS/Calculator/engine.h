#ifndef ENGINE_H
#define ENGINE_H
//#include "Stack.h"
#include <string>
#include <QMessageBox>
using namespace std;

template <class T> class stack {
  public:
    stack();
    ~stack();
    void push(T x);
    void pop();
    T top();
    bool isEmpty();
    bool ok = true;
  private:
    T *data;
    int size;
};
#define maxn 10240
template <class T> stack<T>::stack() {
    size = 0;
    data = new T[10240];
}

template <class T> stack<T>::~stack() {
    delete[] data;
}

template <class T> void stack<T>::push(T x) {
    size++;
    data[size - 1] = x;
}

template <class T> void stack<T>::pop() {
    if(size>0) size--;
    else {
        QMessageBox::warning(NULL,"Error","Excessive symbols found. Please check your input. Calculated result may be inaccurate.");
        ok=false;
    }
}

template <class T> T stack<T>::top() { return data[size - 1]; }

template <class T> bool stack<T>::isEmpty() { return size == 0; }

class Engine
{
private:
    double sqrt(double x);
    double fac(double x);
    double inv(double x);
    void result(string opr);
    bool BracketCheck(string str);
    bool scanCheck(string str);
    bool numericCheck(string str);
    int _atoi(string s,int radix);
    string _itoa(int n,int radix);
    stack<double> num;
    stack<string> op;
    string eq;
    string dl = "(";
    string dr = ")";

public:
    Engine(string s);
    string calc();
    string convert(int predix, int radix);
};

#endif // ENGINE_H
