
#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 30000;

vector<int> G[maxn];
int dep[maxn], fa[maxn], ind[maxn], a[maxn];
struct node {
    int v, ind, deep;
    node(int v = 0, int ind = 0, int deep = 0) : v(v), ind(ind), deep(deep) {}
    bool operator<(const node &r) const {
        if (deep != r.deep)
            return deep < r.deep;
        else if (ind != r.ind)
            return ind < r.ind;
        else
            return v > r.v;
    }
};
void dfs(int u) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    int root = n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t != 0) {
            fa[i] = t;
            ind[t]++;
        }
        G[t].push_back(i);
    }
    dfs(0);
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(node(i, ind[fa[i]], dep[fa[i]]));
        }
    }
    int ans = 0;
    while (1) {
        ans++;
        int num = 0;
        for (int i = 1; i <= k; i++) {
            a[++num] = q.top().v;
            q.pop();
            if (q.empty())
                break;
        }
        for (int i = 1; i <= num; i++) {
            int u = fa[a[i]];
            if (u == 0)
                continue;
            ind[u]--;
            if (ind[u] == 0) {
                q.push(node(u, ind[fa[u]], dep[u]));
            }
                }
        if (q.empty())
            break;
    }
    cout << ans << endl;
    return 0;
}