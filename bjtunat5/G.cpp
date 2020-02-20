#include <bits/stdc++.h>
using namespace std;
#define N 11000
struct dat {
    int id, num;
    inline bool operator<(const dat &a) const { return num > a.num; }
};
priority_queue<dat> Q;
struct sl {
    int next, id;
} e[4 * N];
int kk, head[2 * N], sum[2 * N], i, j, n, m, k, l, siz[2 * N], tot[2 * N], ans,
    fa[2 * N], t[2 * N], root, las;
void add(int x, int y) {
    e[++l].next = head[x];
    e[l].id = y;
    head[x] = l;
}
void dfs(int x, int fa) {
    for (int i = head[x]; i != -1; i = e[i].next) {
        int v = e[i].id;
        if (v == fa)
            continue;
        if (tot[v] != 0)
            siz[x]++;
        else
            sum[x]++;
        if (tot[v] != 0)
            dfs(v, x);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    root = n;
    for (i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0)
            x = ++root;
        tot[x]++;
        fa[i] = x;
        add(x, i);
    }
    for (i = n + 1; i <= root; i++)
        dfs(i, 0);
    for (i = 1; i <= n; i++) {
        if (siz[i] == 0 && tot[i] != 0) {
            dat x;
            x.id = i;
            x.num = sum[i];
            Q.push(x);
        } else if (tot[i] == 0 && fa[i] > n)
            kk++;
    }
    while (!Q.empty() || kk > 0) {
        ans++;
        int now = m;
        k = 0;
        las = kk;
        while (now && !Q.empty()) {
            dat x = Q.top();
            if (now >= x.num) {
                now -= x.num;
                int ff = fa[x.id];
                if (ff <= n) {
                    siz[ff]--;
                    sum[ff]++;
                    if (siz[ff] == 0)
                        t[++k] = ff;
                } else
                    kk++;
                Q.pop();
            } else {
                x.num -= now;
                Q.pop();
                Q.push(x);
                now = 0;
                break;
            }
        }
        kk -= std::min(now, las);
        for (i = 1; i <= k; i++) {
            dat v;
            v.id = t[i];
            v.num = sum[t[i]];
            Q.push(v);
        }
    }
    printf("%d", ans);
}