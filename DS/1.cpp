#include <cstdio>
#include <iostream>

using namespace std;

class node {
  public:
    int c;
    int exp;
    node *next;
    node(int x, int y, node *z = NULL) {
        c = x;
        exp = y;
        next = z;
    }
    node() {}
    ~node() {}
};

class eq {
  public:
    node *head;
    node *cur;
    eq() {
        head = cur = new node();
        head->c = NULL;
        head->next = NULL;
        head->exp = -1;
        cur = head;
    }
    void insert(node *a) {
        node *x = new node();
        x->c = a->c;
        x->exp = a->exp;
        x->next = cur->next;
        cur->next = x;
        cur = x;
    }
    int count() {
        int cnt = 0;
        node *x = head->next;
        while (x != NULL) {
            cnt++;
            x = x->next;
        }
        return cnt;
    }
    ~eq() {}
};

void add(eq &x, eq &y) {
    node *p, *q, *r, *pre;
    p = x.head->next;
    q = y.head->next;
    pre = x.head;
    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            pre = p;
            p = p->next;
        } else if (p->exp == q->exp) {
            int ans = p->c + q->c;
            if (ans != 0) {
                p->c = ans;
                pre = p;
            } else {
                pre->next = p->next;
                free(p);
            }
            p = pre->next;
            r = q;
            q = q->next;
            free(r);
        } else if (p->exp < q->exp) {
            r = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = r;
        }
    }
    if (q != NULL) {
        pre->next = q;
    }
}

void mul(eq &x, eq &y) {
    eq a;
    node *p, *q, *r;
    p = x.head->next;
    bool flag = false;
    while (p != NULL) {
        eq b;
        q = y.head->next;
        while (q != NULL) {
            r = new node();
            r->c = p->c * q->c;
            r->exp = p->exp + q->exp;
            b.insert(r);
            q = q->next;
            delete r;
        }
        if (!flag) {
            a = b;
            flag = true;
        } else {
            add(a, b);
        }
        p = p->next;
    }
    x = a;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    eq x;
    eq y;
    for (int i = 1; i <= n; i++) {
        int c, e;
        cin >> c >> e;
        x.insert(new node(c, e));
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, e;
        cin >> c >> e;
        y.insert(new node(c, e));
    }
    eq xx = x, yy = y;
    add(xx, yy);
    cout << xx.count() << " ";
    node *a = xx.head->next;
    while (a != NULL) {
        cout << a->c << " " << a->exp << " ";
        a = a->next;
    }
    cout << endl;
    xx = x, yy = y;
    mul(xx, yy);
    cout << xx.count() << " ";
    a = xx.head->next;
    while (a != NULL) {
        cout << a->c << " " << a->exp << " ";
        a = a->next;
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
