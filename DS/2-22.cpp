// Compiles under GCC 8.2.0
#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void insert(node *head, int l, int r) {
    node *p = head;
    for (int i = l; i <= r; i++) {
        node *now = (node *)malloc(sizeof(node));
        now->data = i;
        p->next = now;
        p = p->next;
    }
    p->next = NULL;
}

void print(node *head) {
    cout << "The list contains:" << endl;
    node *now = head;
    while (now->next != NULL) {
        now = now->next;
        cout << now->data << " ";
    }
    cout << endl;
}
void flip(node *n) {
    node *x;
    node *y;
    x = n;
    x = x->next;
    n->next = NULL;
    while (x != NULL) {
        y = x;
        x = x->next;
        y->next = n->next;
        n->next = y;
    }
}
int main() {
    node *head = (node *)malloc(sizeof(node));
    cout << "Inserting node 1-10" << endl;
    insert(head, 1, 10);
    print(head);
    cout << "Inverting the list" << endl;
    flip(head);
    print(head);
    return 0;
}
