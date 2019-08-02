#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100010;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 &&
                   (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
inline int _read() {
    char ch = nc();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

struct Node {
    int lc, rc, val;
    Node(int lc = 0, int rc = 0, int val = 0) : lc(lc), rc(rc), val(val) {}
} t[40 * MAXN];

int cnt;

struct FST {
#define mid ((pl + pr) >> 1)

    int size;
    vector<int> root;

    FST(int sz) {
        size = 1;
        while (size < sz)
            size <<= 1;
        root.push_back(N(0, 0, 0));
    }

    int N(int lc, int rc, int val) {
        t[cnt] = Node(lc, rc, val);
        return cnt++;
    }

    int ins(int p, int x, int pl, int pr) {
        if (pl > x || pr < x)
            return p;
        if (pl == pr)
            return N(0, 0, t[p].val + 1);
        return N(ins(t[p].lc, x, pl, mid), ins(t[p].rc, x, mid + 1, pr),
                 t[p].val + 1);
    }

    int ask(int p1, int p2, int k, int pl, int pr) {
        if (pl == pr)
            return pl;
        ll vl = t[t[p2].lc].val - t[t[p1].lc].val;
        if (k <= vl)
            return ask(t[p1].lc, t[p2].lc, k, pl, mid);
        return ask(t[p1].rc, t[p2].rc, k - vl, mid + 1, pr);
    }

    void add(int x) { root.push_back(ins(root.back(), x, 1, size)); }

    int query(int l, int r, int k) {
        return ask(root[l - 1], root[r], k, 1, size);
    }

#undef mid
};

int main() {
    int t, l, r, p, k;
    int tmp;
    t = _read();
    while (t-- > 0) {
        int x = 0;
        int n = _read(), m = _read();
        FST fst = FST(n);
        for (int i = 1; i <= n; i++) {
            tmp = _read();
            fst.add(tmp);
        }
        for (int i = 1; i <= m; i++) {
            l = _read(), r = _read(), p = _read(), k = _read();
            l ^= x, r ^= x, p ^= x, k ^= x;
                }
    }
}