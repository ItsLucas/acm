#include <bits/stdc++.h>

using namespace std;

int a[100010];
int rel[100010];

static constexpr int INF = -0x7f7f7f7f;
struct Node {
    int val;
    Node(int val = 0) : val(val) {}
};

Node merge(const Node &a, const Node &b) { return Node(max(a.val, b.val)); }

struct SegT {
#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid ((pl + pr) >> 1)

    int size;
    Node *t;

    SegT(int sz) {
        size = 1;
        while (size < sz)
            size <<= 1;
        t = new Node[2 * size]();
    }

    ~SegT() { delete[] t; }

    Node ask(int p, int l, int r, int pl, int pr) {
        if (l > pr || r < pl)
            return Node();
        if (l <= pl && r >= pr)
            return t[p];
        return merge(ask(lc, l, r, pl, mid), ask(rc, l, r, mid + 1, pr));
    }

    void update(int k, int val) {
        int p = size + k - 1;
        t[p] = Node(val);
        for (p >>= 1; p > 0; p >>= 1) {
            t[p] = merge(t[lc], t[rc]);
        }
    }

    Node query(int l, int r) { return ask(1, l, r, 1, size); }

#undef lc
#undef rc
#undef mid
};

int main() {
    int t, n, k;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &n, &k);
        SegT st = SegT(n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            a[i] = x;
            st.update(i, x);
        }
        memset(rel, 0, sizeof(rel));
        for (int i = 1; i <= n; i++) {
            printf("%d %d\n", max(i - k, 1), min(i + k, n));
            rel[i] = st.query(max(i - k, 1), min(i + k, n)).val;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d-->%d\n", i, rel[i]);
        }
    }
    return 0;
}