#include <bits/stdc++.h>
#define N 310000
struct sl {
    int x, y, id;
} a[N], b[N], g[2];
struct sa {
    int x, id, pd;
} t[2 * N];
struct sg {
    int x, id;
};
int bit[2 * N][2], i, j, n, m, k, o, l, tot, ans, x, y, q[2 * N];
bool cmp1(sa x, sa y) { return x.x < y.x; }
bool cmp2(sl x, sl y) { return x.x > y.x; }
bool cmp3(sl x, sl y) { return x.y > y.y; }
void add(int x, int num, int id) {
    int i;
    for (i = x; i <= o; i += (i & -i)) {
        if (bit[i][0] < num)
            bit[i][0] = num, bit[i][1] = id;
    }
}
sg query(int x, int id) {
    int i;
    sg ans;
    ans.x = 0, ans.id = 0;
    for (i = x; i; i -= (i & -i)) {
        if (bit[i][0] > ans.x && bit[i][1] != id)
            ans.x = bit[i][0], ans.id = bit[i][1];
    }
    return ans;
}
int main() {
    // freopen("F.in","r",stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
        t[++tot].x = a[i].x;
        t[tot].id = i;
        t[tot].pd = 1;
        t[++tot].x = a[i].y;
        t[tot].id = i;
        t[tot].pd = 2;
    }
    std::sort(t + 1, t + tot + 1, cmp1);
    o = 0;
    for (i = 1; i <= tot; i++) {
        if (t[i].x != t[i - 1].x)
            o++;
        q[o] = t[i].x;
        if (t[i].pd == 1)
            a[t[i].id].x = o;
        if (t[i].pd == 2)
            a[t[i].id].y = o;
    }
    for (i = 1; i <= n; i++)
        b[i] = a[i];
    std::sort(a + 1, a + n + 1, cmp2);
    std::sort(b + 1, b + n + 1, cmp3);
    l = 1;
    tot = 0;
    ans = 0;
    x = 1;
    y = 2;
    for (i = 1; i <= n; i++) {
        while (a[l].x >= b[i].y && l <= n)
            add(a[l].y, a[l].x, a[l].id), l++;
        sg pp = query(b[i].x, b[i].id);
        int maxn = q[pp.x];
        int p = l - 1;
        if (pp.id == 0)
            while (a[p].id == b[i].id && p >= 1)
                p--;
        if (p != 0)
            maxn += q[b[i].x];
        if (maxn > ans) {
            ans = maxn;
            x = pp.id;
            y = b[i].id;
            if (x == 0)
                x = a[p].id;
        }
    }
    printf("%d\n%d %d", ans, x, y);
}