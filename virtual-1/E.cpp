#include <bits/stdc++.h>

using namespace std;
const int N = 200005, M = 200005;
struct dat {
    int l, r, ans, id;
} q[M];

struct node {
    int t, dur;
};

node a[N], b[N];
int n, m, siz, tot, blk[N], res, L, R, cnt[N];

inline bool cmp1(dat a, dat b) {
    return blk[a.l] < blk[b.l] ||
           (blk[a.l] == blk[b.l] && (blk[a.l] & 1 ? a.r < b.r : a.r > b.r));
}
inline bool cmp2(dat a, dat b) { return a.id < b.id; }
inline int find(int x) {
    int l = 1, r = tot, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (b[mid].dur == x)
            return mid;
        if (b[mid].dur < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
}
inline void add(int col) {
    if (++cnt[col] == 1)
        ++res;
}
inline void del(int col) {
    if (--cnt[col] == 0)
        --res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].dur;
        b[i] = a[i];
        blk[i] = (i - 1) / siz + 1;
    }
}