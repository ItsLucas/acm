#include <bits/stdc++.h>

#define nop (void)0

using namespace std;

static constexpr int maxn = 200040;

struct oo_t {
    inline long long operator+() { return 1e18; }
    inline long long operator-() { return -1e18; }
} oo;

long long INF = +oo;

int n, m;
int root, deg[maxn], dep[maxn], val[maxn], a[maxn], fa[maxn][20];
vector<int> E[maxn], G[maxn], T[maxn];

void bfs() {
    queue<int> q;
    root = n + 1;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            q.push(i);
            E[root].push_back(i);
            G[i].push_back(root);
        }
    }
    int tot = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        a[++tot] = u;
        for (int v : E[u]) {
            if ((--deg[v]) == 0) {
                q.push(v);
            }
        }
    }
}

int lca(int x, int y) {
    dep[x] > dep[y] ? swap(x, y) : nop;
    for (int i = 19; i >= 0; i--) {
        if (dep[y] > dep[x] && dep[fa[y][i]] >= dep[x]) {
            y = fa[y][i];
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return x == y ? x : fa[x][0];
}

void init() {
    for (int i = 1; i <= n + 1; i++) {
        E[i].clear();
        G[i].clear();
        T[i].clear();
        dep[i] = deg[i] = 0;
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &n, &m);
        init();
        int u, v, q;
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            E[v].push_back(u);
            G[u].push_back(v);
            deg[u]++;
        }
        bfs();
        dep[root] = 1;
        for (int i = 1; i <= n; i++) {
            int u = a[i], _fa = -1;
            for (int v : G[u]) {
                _fa == -1 ? _fa = v : _fa = lca(_fa, v);
                dep[u] = dep[_fa] + 1;
                fa[u][0] = _fa;
                T[_fa].push_back(u);
                for (int i = 1; i <= 19; i++) {
                    fa[u][i] = fa[fa[u][i - 1]][i - 1];
                }
            }
        }
        scanf("%d", &q);
        while (q-- > 0) {
            scanf("%d %d", &u, &v);
            printf("%d\n", dep[u] + dep[v] - dep[lca(u, v)] - 1);
        }
    }
}