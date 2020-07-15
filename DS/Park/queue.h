#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_MAX_LEN 1025
template<class T>
class queue
{
public:
    queue(int len);
    queue();
    void push(T x);
    T top();
    void pop();
    bool empty();
    void setsize(int len);
    bool full();
    int getsize();
private:
    T *data;
    int size;
    int tail;
    int front;
    int maxsize;
};
#include <queue_impl.h>
#endif // QUEUE_H
