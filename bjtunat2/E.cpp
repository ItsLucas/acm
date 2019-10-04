#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define ls (u << 1)
#define rs (ls | 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r

using namespace std;
const int maxn = 3e5 + 10;
int tr[maxn << 2];
void pushdown(int u) {
    if (tr[u]) {
        tr[ls] = tr[u];
        tr[rs] = tr[u];
    }
}
int chk(int u, int l, int r, int x) {
    if (l == r) {
        return tr[u];
    }
    // cerr << l << " " << r << " " << x << endl;
    // system("pause");
    pushdown(u);
    if (x <= mid)
        return chk(lc, x);
    else
        return chk(rc, x);
}
void modify(int u, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        tr[u] = x;
        // cerr << u << " " << tr[u] << endl;
        return;
    }
    pushdown(u);
    if (ql <= mid)
        modify(lc, ql, qr, x);
    if (qr > mid)
        modify(rc, ql, qr, x);
}
int a[maxn];
int n, m;
vector<int> L[maxn], R[maxn];
void built(int u, int l, int r) {
    if (l == r) {
        printf("%d ", tr[u] ? tr[u] : a[l]);
        return;
    }
    pushdown(u);
    built(lc);
    built(rc);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = n; i; --i) {
        R[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        L[a[i]].push_back(i);
    }
    cin >> m;
    for (int kas = 1, x; kas <= m; ++kas) {
        scanf("%d", &x);
        // cerr << L[x].size() << " " << R[x].size() << endl;
        while (L[x].size() != 0 && chk(1, 1, n, L[x][0]) != 0) {
            L[x].erase(L[x].begin());
        }
        while (R[x].size() != 0 && chk(1, 1, n, R[x][0]) != 0) {
            R[x].erase(R[x].begin());
        }
        // cerr << L[x].size() << " " << R[x].size() << endl;
        // cerr << L[x][0] << " " << R[x][0] << endl;
        //;
        if (L[x].size() == 0 || R[x].size() == 0)
            continue;
        modify(1, 1, n, L[x][0], R[x][0], x);
    }
    built(1, 1, n);
}
int main() {
    solve();

    return 0;
}