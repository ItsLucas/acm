#ifndef MONKEY_H
#define MONKEY_H

struct node {
    int data;
    node *next;
};

class monkey
{
private:
    node *head;
    node *p,*q;
    int cnt;
    int num;
public:
    monkey();
    monkey(int n,int m);
    bool isempty();
    int next();
    int king();
};

#endif // MONKEY_H
