#include <bits/stdc++.h>

using namespace std;

struct BTree {
    char ch;
    BTree *l, *r;
};

BTree *build(char a[], char b[], int l1, int r1, int l2, int r2) {
    BTree *root = (BTree *)malloc(sizeof(BTree));
    root->ch = a[l1];
    int i = l2;
    for (i; b[i] != a[l1]; i++)
        ;
    int ll = i - l2;
    int rl = r2 - i;
    root->l = (ll > 0 ? build(a, b, l1 + 1, l1 + ll, l2, ll + l2 - 1) : NULL);
    root->r = (rl > 0 ? build(a, b, r1 - rl + 1, r1, r2 - rl + 1, r2) : NULL);
    return root;
}

void p(BTree *bt) {
    if (bt != NULL) {
        cout << bt->ch << " ";
        p(bt->l);
        p(bt->r);
    }
}
int main() {
    int n;
    cin >> n;
    char a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    BTree *bt = build(a, b, 1, n, 1, n);
    p(bt);
    cout << endl;
    return 0;
}