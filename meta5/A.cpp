#include <bits/stdc++.h>
using namespace std;
#define N 1000100
struct sl {
    int next, id, dis, typ;
} e[N];
int dis[N], i, j, n, m, sum[N], head[N], m1, m2, tot, T;
bool vise[N];

void add(int x, int y, int z, int typ) {
    e[++tot].next = head[x];
    e[tot].id = y;
    e[tot].dis = z;
    e[tot].typ = typ;
    head[x] = tot;
}
bool spfa(int mid) {
    queue<int> q;
    while (!q.empty())
        q.pop();
    e[tot].dis = -mid;
    e[tot - 1].dis = mid;
    int s = 0;
    for (int i = 0; i <= n; ++i) {
        dis[i] = 0x7f7f7f7f;
        vise[i] = false;
        sum[i] = 0;
    }
    // memset(dis, 0x7f, sizeof(dis));
    // memset(vise, false, sizeof(vise));
    // memset(sum, 0, sizeof(sum));
    q.push(s);
    sum[s]++;
    vise[s] = true;
    dis[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vise[x] = false;
        for (i = head[x]; i != -1; i = e[i].next) {
            int v = e[i].id, tmp = (e[i].typ) ? e[i].dis + mid : e[i].dis;
            if (dis[x] + tmp < dis[v]) {
                dis[v] = dis[x] + tmp;
                if (dis[v] < 0)
                    return false;
                if (!vise[v]) {
                    q.push(v);
                    vise[v] = true;
                    sum[v]++;
                    if (sum[v] > n)
                        return false;
                }
            }
        }
    }
    if (dis[n] == 0x7f7f7f7f)
        return false;
    return true;
}
void mian() {
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
    }
    // memset(head, -1, sizeof(head));
    tot = 0;
    for (i = 1; i <= n; ++i) {
        add(i, i - 1, 0, 0);
        add(i - 1, i, 1, 0);
    }
    for (i = 1; i <= m1; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        add(r, l - 1, -k, 0);
    }
    for (i = 1; i <= m2; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        add(l - 1, r, -k, 1);
    }
    add(0, n, 0, 0);
    add(n, 0, 0, 0);
    int l = 0, r = n, mid, ans = n;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (spfa(mid))
            r = (ans = mid) - 1;
        else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    for (; T--;)
        mian();
    return 0;
}