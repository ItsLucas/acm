#include <bits/stdc++.h>

struct node {
    int data;
    struct node *next;
};

#define NULL 0

// Time Complexity: O(r-l)
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