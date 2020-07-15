#include "queue.h"
template<class T>
queue<T>::queue()
{
    data = new T[1024];
    size=0;
    maxsize=1024;
    front=0;
    tail=0;
}

template<class T>
queue<T>::queue(int len)
{
    data = new T[len];
    size=0;
    maxsize=len;
    front=0;
    tail=0;
}

template<class T>
void queue<T>::setsize(int len){
    maxsize=len;
}

template<class T>
void queue<T>::push(T x) {
    if(size==maxsize) {
        return;
    }
    data[tail]=x;
    size++;
    if(tail==maxsize-1) {
        tail=0;
    }
    else tail++;
}

template<class T>
T queue<T>::top() {
    return data[front];
}

template<class T>
void queue<T>::pop() {
    if(size==0) {
        return;
    }
    else {
        size--;
        if(front==maxsize-1) {
            front=0;
        }
        else front++;
    }
}

template<class T>
bool queue<T>::empty() {
    return size==0;
}

template<class T>
bool queue<T>::full() {
    return size==maxsize;
}

template<class T>
int queue<T>::getsize() {
    return size;
}
