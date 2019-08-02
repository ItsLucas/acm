#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 300050;

struct node {
    vector<int> e[maxn];
    inline void add(int u, int v) { e[u].push_back(v); }
} a, b, c, d;

int dfn[maxn], id[maxn], dfa[maxn], sdom[maxn], idom[maxn], fa[maxn],
    mindfn[maxn], cnt;

void dfs(int u) {
    dfn[u] = ++cnt;
    id[cnt] = u;
    for (int i : a.e[u]) {
        if (dfn[i]) {
            continue;
        }
        dfa[i] = u;
        dfs(i);
    }
}

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    int tmp = find(fa[x]);
    if (dfn[sdom[mindfn[fa[x]]]] < dfn[sdom[mindfn[x]]]) {
        mindfn[x] = mindfn[fa[x]];
    }
    return fa[x] = tmp;
}

void zp() {
    for (int i = cnt; i > 1; i--) {
        int u = id[i];
        for (int v : b.e[u]) {
            if (!dfn[v]) {
                continue;
            }
            find(v);
            if (dfn[sdom[mindfn[v]]] < dfn[sdom[u]]) {
                sdom[u] = sdom[mindfn[v]];
            }
        }
        c.add(sdom[u], u);
        fa[u] = dfa[u];
        u = fa[u];
        for (int v : c.e[u]) {
            find(v);
            sdom[mindfn[v]] == u ? idom[v] = u : idom[v] = mindfn[v];
        }
    }
    for (int i = 2; i <= cnt; i++) {
        int u = id[i];
        if (idom[u] != sdom[u]) {
            idom[u] = idom[idom[u]];
        }
    }
}

void zp_write(int n) {
    for (int i = 2; i <= n; i++) {
        d.add(idom[i], i);
    }
}

int ans[maxn];

void dfs2(int u) {
    ans[u] = 1;
    for (int i : d.e[u]) {
        dfs2(i);
        ans[u] += ans[i];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a.add(u, v);
        b.add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        sdom[i] = fa[i] = mindfn[i] = i;
    }
    dfs(1);
    zp();
    zp_write(n);
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}