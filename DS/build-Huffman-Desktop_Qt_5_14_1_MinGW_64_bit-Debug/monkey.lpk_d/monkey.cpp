#include "monkey.h"

monkey::monkey()
{
    head = new node;
    head->data=1;
    head->next=head;
}

monkey::monkey(int n,int m) {
    cnt=n;
    num=m;
    head = new node;
    head->data=1;
    head->next=head;
    for(int i=n;i>=2;i--) {
        p=new node;
        p->data=i;
        p->next=head->next;
        head->next=p;
    }
    q=head;
}

bool monkey::isempty() {
    return q->next==q;
}

int monkey::next() {
    for(int i=1;i<=num-2;i++) {
        q=q->next;
    }
    p=q->next;
    int ret = p->data;
    q->next=p->next;
    delete p;
    q=q->next;
    return ret;
}

int monkey::king() {
    return q->data;
}
