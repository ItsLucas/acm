#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static constexpr int maxn = 100010;

struct node {
    int v;
    ll w;
    node(int v = 0, ll w = 0) : v(v), w(w){};
};

vector<node> G[maxn];

int n, t, m, siz[maxn];
ll dp[maxn][102];

inline void init(int n, int m) {
    memset(siz, 0, sizeof(siz));
    for (int i = 0; i <= n; i++)
        G[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }
}

int getroot(int n) {
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() >= 2) {
            ret = i;
            break;
        }
    }
    return ret;
}

void dfs(int u, int pa) {
    dp[u][0] = 0;
    if (G[u].size() == 1) {
        siz[u] = 1;
        dp[u][1] = 0;
    }
    for (node i : G[u]) {
        int v = i.v;
        ll w = i.w;
        if (v == pa) {
            continue;
        }
        dfs(v, u);
        siz[u] += siz[v];
        dp[u][m] = min(dp[u][m], dp[v][m]);
        for (int j = min(m, siz[u]); j >= 1; j--) {
            for (int k = 1; k <= min(j, siz[v]); k++) {
                dp[u][j] = min(dp[u][j], dp[u][j - k] + dp[v][k] +
                                             (ll)w * (ll)k * (ll)(m - k));
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        init(n, m);
        int u, v;
        ll w;
        for (int i = 1; i <= n - 1; i++) {
            scanf("%d %d %lld", &u, &v, &w);
            G[u].push_back(node(v, w));
            G[v].push_back(node(u, w));
        }
        int root = getroot(n);
        dfs(root, -1);
        printf("Case #%d: %lld\n", tt, dp[root][m]);
    }
    return 0;
}