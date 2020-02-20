#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1010;

vector<int> G[maxn];
int now, fa[maxn], vis[maxn];

bool dfs(int u) {
    for (int v : G[u]) {
        if (vis[v] == now)
            continue;
        vis[v] = now;
        if (!fa[v] || dfs(fa[v])) {
            fa[v] = u;
            return true;
        }
    }
    return false;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int t, tt;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            cin >> tt;
            G[i].push_back(tt);
        }
        G[i + n] = G[i];
    }
    int a = 0, b = 0;
    now = 0;
    for (int i = 1; i <= n; i++) {
        now++;
        if (dfs(i))
            a++;
    }
    for (int i = 1; i <= n; i++) {
        now++;
        if (dfs(i + n))
            b++;
    }
    cout << a + min(b, k) << endl;
    return 0;
}