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

// Time Complexity: O(r-1)

bool del(node *head, int l, int r) {
    node *pl;
    node *pr;
    pl = head->next;
    pr = head->next;
    while (pr->data <= l && pr != NULL) {
        pl = pr;
        pr = pr->next;
    }
    if (!pr) {
        return false;
    }
    while (pr->data < r && pr != NULL) {
        pl->next = pr->next;
        free(pr);
        pr = pl->next;
    }
    return true;
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
int main() {
    node *head = (node *)malloc(sizeof(node));
    cout << "Inserting node 1-10" << endl;
    insert(head, 1, 10);
    print(head);
    cout << "Deleting node from (3,8)" << endl;
    del(head, 3, 8);
    print(head);
    return 0;
}
