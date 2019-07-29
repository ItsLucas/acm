#include <bits/stdc++.h>

using namespace std;

static constexpr int INF = 0x7ffffaff;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct node {
    int v, w;
    node(int v = 0, int w = 0) : v(v), w(w){};
    inline bool operator<(const node &a) const { return w < a.w; }
};

void __update(node &a, node &b) {
    if (a.v == b.v) {
        a.w += b.w;
    }
}

node _update(node x, node y) {
    node tmp = node(gcd(x.v, y.v));
    __update(tmp, x);
    __update(tmp, y);
    return tmp;
}

// thanks for qdd's segment tree template :)

struct SegT {
#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid (pl + pr >> 1)

    int size;
    node *t;

    SegT(int sz) {
        size = 1;
        while (size < sz)
            size <<= 1;
        t = new node[2 * size]();
    }

    ~SegT() { delete[] t; }

    node ask(int p, int l, int r, int pl, int pr) {
        if (l > pr || r < pl)
            return node();
        if (l <= pl && r >= pr)
            return t[p];
        node vl = ask(lc, l, r, pl, mid);
        node vr = ask(rc, l, r, mid + 1, pr);
        return _update(vl, vr);
    }

    void update(int k, int val) {
        int p = size + k - 1;
        t[p] = node(val, 1);
        for (p >>= 1; p > 0; p >>= 1) {
            t[p] = _update(t[lc], t[rc]);
        }
    }

    node query(int l, int r) { return ask(1, l, r, 1, size); }

#undef lc
#undef rc
#undef mid
};

int main() {
    int n, q, x;
    cin >> n;
    SegT st(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        st.update(i, x);
    }
    cin >> q;
    int l, r;
    while (q-- > 0) {
        cin >> l >> r;
        int p = r - l + 1;
        cout << p - st.query(l, r).w << endl;
    }
    return 0;
}
