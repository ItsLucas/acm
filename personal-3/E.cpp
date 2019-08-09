#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 100010;
static constexpr int mod = 1e9 + 7;
struct node {
    int v, w;
    node(int v = 0, int w = 0) : v(v), w(w){};
};

vector<node> G[maxn];
int a[maxn];

inline void add(int u, int v, int w) {
    G[u].push_back(node(v, w));
    G[v].push_back(node(u, w));
}

bool dfs(int k, int val) {
    if (a[k] >= 0) {
        return a[k] == val;
    }
    a[k] = val;
    for (auto i : G[k]) {
        if (!dfs(i.v, val ^ i.w ^ 1)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    int ans = 5e8 + 4;
    int nop = 1;
    for (int i = 1; i <= n; i++) {
        a[i] < 0 ? !dfs(i, 0) ? ans = 0 : ans = ans * 2 % mod : nop = 1;
    }
    cout << ans << endl;
    return 0;
}
