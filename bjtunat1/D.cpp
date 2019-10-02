#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int dep[maxn], f[maxn];
vector<int> G[maxn];
bool cmp(int a, int b) { return dep[a] > dep[b]; }
void dfs(int u) {
    if (G[u].size() == 0) {
        dep[u] = 1;
        return;
    }
    for (int i = 0, v; i < G[u].size(); ++i) {
        v = G[u][i];
        dfs(v);
    }
    sort(G[u].begin(), G[u].end(), cmp);
    dep[u] = dep[G[u][0]] + 1;
    dep[G[u][0]] = 0;
}
int k;
void solve() {
    // cin>>n;
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", f + i);
        G[f[i]].push_back(i);
    }
    dfs(1);
    sort(dep + 1, dep + n + 1, greater<int>());
    long long ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dep[i];
    }
    cout << ans << endl;
    // printf("%lld\n",ans)
}
int main() {
    solve();

    return 0;
}