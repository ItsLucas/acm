#include <bits/stdc++.h>

#define maxn 201010
using namespace std;
struct node {
    int id, s, t;
} a[maxn];
int n, t;
node cache[201010];
bool cmp(node u, node v) { return u.s < v.s || (u.s == v.s && u.t > v.t); }
void work() {
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].s, &a[i].t);
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    int beg = 1, i = 0, ans = 0, maxx = 0, pos = 1;
    while (true) {
        bool flag = false;
        node x;
        for (; i < n; ++i) {
            if (a[i].s > beg)
                break;
            flag = true;
            if (a[i].t >= maxx) {
                x = a[i];
                maxx = a[i].t;
            }
            // maxx = max(maxx, a[i].t);
        }
        if (!flag || maxx < beg) {
            ans = -1;
            break;
        }
        ++ans;
        beg = maxx + 1;
        cache[pos++] = {x.id, x.s, x.t};
        if (beg == t + 1)
            break;
    }
    if (ans != -1) {
        printf("YES\n");
        printf("%d\n", ans);
        for (int i = 1; i <= pos - 1; i++) {
            printf("%d ", cache[i].id);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}
int main() {
    scanf("%d%d", &n, &t);
    work();
    return 0;
}
