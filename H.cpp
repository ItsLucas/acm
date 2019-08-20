#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
    int next;
    int u, v, w;
} e[2 * 100005], s[2 * 100005];
int head[100005], shead[100005];
int cnt;
int fa[100005];
int sum;
int dep[100005];
int up[100005][22];
int f[100005][22];
int q;
map<pair<int, int>, int> mp;
void add(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].u = u;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
bool cmp(node e1, node e2) { return e1.w < e2.w; }
int find(int now) {
    if (fa[now] == now)
        return now;
    else
        return find(fa[now]);
}
void tomerge(int x, int y) { fa[fa[x]] = fa[y]; }
void add2(int u, int v, int w) {
    s[++cnt].v = v;
    s[cnt].w = w;
    s[cnt].next = shead[u];
    shead[u] = cnt;
}
void kruskal() {
    for (int i = 1; i <= 2 * m; i++) {
        int now = e[i].u, to = e[i].v;
        if (find(now) == find(to))
            continue;
        else {
            sum += e[i].w;
            add2(now, e[i].v, e[i].w);
            add2(e[i].v, now, e[i].w);
            tomerge(now, to);
        }
    }
    //   printf("sum %d\n", sum);
}
void dfs(int u, int F, int w) {
    dep[u] = dep[F] + 1;
    up[u][0] = F;
    f[u][0] = w;

    for (int i = 1; i <= 21; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    //  printf("u %d %d\n", u, up[u][1]);
    for (int i = 1; i <= 21; i++)
        f[u][i] = max(f[u][i - 1], f[up[u][i - 1]][i - 1]);

    for (int i = shead[u]; i; i = s[i].next) {
        if (s[i].v != F)
            dfs(s[i].v, u, s[i].w);
    }
}
int findlca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);
    //   printf("u v %d %d\n", u, v);
    int t = dep[v] - dep[u];
    //   printf("t %d\n", t);
    for (int i = 0; i <= 21; i++)
        if ((t >> i) & 1) {
            //         printf("v %d %d %d\n", v, i, up[v][i]);
            v = up[v][i];
        }

    //   printf("%d %d\n", u, v);
    if (u == v)
        return u;
    //  printf("%d %d\n", u, v);
    for (int i = 21; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    //   printf("lca %d %d\n", u, up[u][0]);
    return up[u][0];
}
int getlen(int u, int v) {
    int x = 0;
    if (dep[u] > dep[v])
        swap(u, v);
    int t = dep[v] - dep[u];
    for (int i = 21; i >= 0; i--) {
        if ((t >> i) & 1) {
            x = max(f[v][i], x);
            //       printf("%d %d %d\n", v, i, x);
            v = up[v][i];
        }
    }
    return x;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
        mp[make_pair(min(u, v), max(u, v))] = w;
    }
    sort(e + 1, e + 2 * m + 1, cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    kruskal();
    cnt = 0;
    dfs(1, 0, 0);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int vq = mp[make_pair(min(x, y), max(x, y))];
        int lca = findlca(x, y);
        int len1 = getlen(lca, x), len2 = getlen(lca, y);
        //   printf("%d %d %d %d\n", vq, lca, len1, len2);
        printf("%d\n", sum + vq - max(len1, len2));
    }
    return 0;
}