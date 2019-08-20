#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 100005;

int pa[maxn];
int n, e, sum = 0;
int find(int x) { return (x == pa[x]) ? x : pa[x] = find(pa[x]); }
void merge(int a, int b) { pa[find(a)] = find(b); }

struct node {
    int u, v, d;
    node(int u, int v, int d) : u(u), v(v), d(d){};
    node(){};
    inline bool operator<(const node &b) const {
        if (d != b.d)
            return d < b.d;
        if (u != b.u)
            return u < b.u;
        return v < b.v;
    }
};

vector<pair<int, int>> G[maxn];
vector<node> es;

void kruscal() {
    sort(es.begin(), es.end());
    for (int i = 0; i < e; i++) {
        if (find(es[i].u) != find(es[i].v)) {
            merge(es[i].u, es[i].v);
            G[es[i].u].push_back(make_pair(es[i].v, es[i].d));
            G[es[i].v].push_back(make_pair(es[i].u, es[i].d));
            sum += es[i].d;
        }
    }
}

int fa[maxn];
bool vis[maxn];
int depp[maxn];
int M[maxn];
int f[maxn][18];
int P[maxn][18];

void dfs(int u, int dep) {
    vis[u] = 1;
    depp[u] = dep;
    for (int i = 0; i < G[u].size(); i++) {
        if (!vis[G[u][i].first]) {
            M[G[u][i].first] = G[u][i].second;
            fa[G[u][i].first] = u;
            dfs(G[u][i].first, dep + 1);
        }
    }
}

void getM() {
    memset(P, -1, sizeof(P));
    for (int i = 0; i < n; i++)
        P[i][0] = fa[i];
    for (int i = 0; i < n; i++)
        f[i][0] = M[i];
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i < n; i++) {
            if (P[i][j - 1] != -1) {
                P[i][j] = P[P[i][j - 1]][j - 1];
                f[i][j] = max(f[i][j - 1], f[P[i][j - 1]][j - 1]);
            }
        }
    }
    return;
}

int lca(int a, int b) {
    if (depp[a] < depp[b])
        swap(a, b);
    for (int i = 16; i >= 0; i--) {
        if (depp[a] - (1 << i) >= depp[b]) {
            a = P[a][i];
        }
    }
    if (a == b)
        return b;
    for (int i = 16; i >= 0; i--) {
        if (P[a][i] != P[b][i]) {
            a = P[a][i];
            b = P[b][i];
        }
    }
    return fa[a];
}

int em(int a, int b) {
    int dif = depp[a] - depp[b];
    int dev = 0;
    for (int i = 16; i >= 0; i--)
        if (depp[a] - depp[b] >= (1 << i)) {
            dev = max(dev, f[a][i]);
            a = P[a][i];
        }
    return dev;
}

int main() {
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; i++)
        pa[i] = i;
    map<pair<int, int>, int> m;
    int u, v, w;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        es.push_back(node(u, v, w));
        m[make_pair(min(u, v), max(u, v))] = w;
    }
    kruscal();
    dfs(0, 0);
    getM();
    int q;
    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%d %d", &u, &v);
        u--, v--;
        int x = lca(u, v);
        int vq = m[make_pair(min(u, v), max(u, v))];
        printf("%d\n", sum + vq - max(em(u, x), em(v, x)));
    }
    return 0;
}