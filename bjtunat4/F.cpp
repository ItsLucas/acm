#include <bits/stdc++.h>
using namespace std;

#define lson root << 1
#define rson root << 1 | 1

const int maxn = 1e5 + 10;
typedef long long ll;

ll ans1[maxn], ans2[maxn], tech[maxn], val[maxn];
vector<int> G[maxn];

ll tree[maxn << 2];
void build(int l, int r, int v) { memset(tree, v, sizeof(tree)); }
void update(int root, int left, int right, int pos, int k) {
    if (pos < left || pos > right)
        return;
    if (left == right) {
        tree[root] += k;
        return;
    }
    int mid = (left + right) >> 1;
    update(lson, left, mid, pos, k);
    update(rson, mid + 1, right, pos, k);
    tree[root] = tree[lson] + tree[rson];
}

ll query(int root, int left, int right, int ql, int qr) {
    if (qr < left || ql > right)
        return 0;
    if (ql <= left && right <= qr)
        return tree[root];
    int mid = (left + right) >> 1;
    return query(lson, left, mid, ql, qr) + query(rson, mid + 1, right, ql, qr);
}
ll qu(int l, int r) { return query(1, 0, maxn, l, r); }
void up(int p, int k) { update(1, 0, maxn, p, k); }

void dfs(int s) {
    ans1[s] = qu(0, tech[s] - 1);
    up(tech[s], val[s]);
    for (int i : G[s]) {
        dfs(i);
        ans2[i] = qu(0, tech[i] - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r;
    cin >> n;
    build(1, n, 0);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u >> tech[i] >> val[i];
        if (u == -1) {
            r = i;
        } else
            G[u].push_back(i);
    }
    dfs(r);
    ans2[r] = qu(0, tech[r] - 1);
    for (int i = 1; i <= n; i++) {
        cout << ans2[i] - ans1[i] << endl;
    }
    return 0;
}
