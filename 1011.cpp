#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100010;

int n, q;
bool flag = true;

namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <typename T> inline void read(T &x) {
    char ch;
    while (blank(ch = nc()))
        ;
    if (IOerror)
        return;
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
}
#undef BUF_SIZE
}; // namespace fastIO

using namespace fastIO;

const ll INF = 1e18;
struct Node {
    int val;
};

struct SegT {
#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid (pl + pr >> 1)

    ll size;
    Node *t;

    SegT(ll sz) {
        size = 1;
        while (size < sz)
            size <<= 1;
        t = new Node[2 * size]();
    }

    ~SegT() { delete[] t; }

    void add(int x, ll val) {
        int p = size + x - 1;
        t[p].val += val;
        for (p >>= 1; p > 0; p >>= 1) {
            t[p].val += val;
        }
    }

    ll ask(int p, ll k, int pl, int pr) {
        if (pl == pr)
            return pl;
        if (k <= t[lc].val)
            return ask(lc, k, pl, mid);
        return ask(rc, k - t[lc].val, mid + 1, pr);
    }

    ll query(ll k) { return ask(1, k, 1, size); }

#undef lc
#undef rc
#undef mid
};

int main() {
    while (1) {
        read(n);
        if (IOerror == 1)
            return 0;
        read(q);
        SegT st = SegT(n);
        ll tmp;
        for (int i = 1; i <= n; i++) {
            read(tmp);
            st.add(tmp, 1);
        }
        int l, r;
        for (int i = 1; i <= q; i++) {
            read(l);
            read(r);
            if (r - l < 2) {
                printf("-1\n");
                continue;
            }
            int cnt = 0;
            while (cnt <= 43) {
                cnt++;
                int a = st.ask(1, cnt, l, r);
                int b = st.ask(1, cnt + 1, l, r);
                int c = st.ask(1, cnt + 2, l, r);
                if (a < b + c) {
                    printf("%d\n", a + b + c);
                    break;
                }
            }
        }
    }
    return 0;
}