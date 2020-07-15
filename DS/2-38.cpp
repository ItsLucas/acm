#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *pre;
    node *next;
    int freq;
};
void insert(node *L, int val, int i) {
    node *p = L->next;
    node *p2;
    int cnt = 1;
    while (cnt < i) {
        cnt++;
        p = p->next;
    }
    p2 = (node *)malloc(sizeof(node));
    p2->data = val;
    p2->next = p;
    p2->pre = p->pre;
    p->pre->next = p2;
    p->pre = p2;
}
void print(node *L) {
    node *p = L->next;
    while (p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void elevate(node *L, node *p1, node *p2) {
    p2->freq++;
    p1 = p2->next;
    p1->pre = p2->pre;
    p2->pre->next = p1;
    p1 = L->next;
    while (p1 != L && p1->freq > p2->freq)
        p1 = p1->next;
    p2->next = p1;
    p1->pre->next = p2;
    p2->pre = p1->pre;
    p1->pre = p2;
}
void locate(node *L, int val) {
    node *p1;
    node *p2;
    p1 = L;
    p2 = p1->next;
    while (p2 != L && p2->data != val)
        p2 = p2->next;
    if (p2 != L) {
        elevate(L, p1, p2);
        return;
    } else
        return;
}
int main() {
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = head;
    head->pre = head;
    cout << "Inserting 1-10" << endl;
    for (int i = 1; i <= 10; i++) {
        insert(head, i, i);
    }
    print(head);
    cout << "looking up 5 for 5 times" << endl;
    locate(head, 5);
    locate(head, 5);
    locate(head, 5);
    locate(head, 5);
    locate(head, 5);
    print(head);
    return 0;
}