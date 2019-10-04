#include <bits/stdc++.h>
#define N 210000
struct sl {
    int time, id;
} t[N];
int ans[N], i, j, n, m, k, l, o, p, now;
bool cmp(sl x, sl y) { return x.time < y.time; }
int main() {
    scanf("%d%d%d", &n, &m, &k);
    k++;
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i].time);
        t[i].id = i;
    }
    std::sort(t + 1, t + n + 1, cmp);
    now = 1;
    ans[t[1].id] = now;
    l = 1;
    for (i = 2; i <= n; i++) {
        if (t[l].time + k <= t[i].time)
            ans[t[i].id] = ans[t[l].id], l++;
        else
            ans[t[i].id] = ++now;
    }
    printf("%d\n", now);
    for (i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d", ans[n]);
}