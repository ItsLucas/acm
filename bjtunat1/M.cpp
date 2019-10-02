#include <bits/stdc++.h>
using namespace std;
#define N 110000
int a[N], i, j, n, m, k, mid, r, ans, l;
bool check(int x) {
    int i, j, sum, now = 0;
    sum = 1;
    for (i = 1; i <= n; i++) {
        now += a[i];
        int o = now / x;
        if (o * x < now)
            o++;
        if (o > x)
            sum++, now = a[i];
    }
    if (sum <= m)
        return true;
    else
        return false;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        r += a[i];
    }
    int s = l;
    l /= k;
    if (l * k < s)
        l++;
    r /= k;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d", ans);
}