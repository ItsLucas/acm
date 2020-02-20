#include <bits/stdc++.h>
#define N 510000
struct sl {
    int x, y, z;
} a[N];
int t[N], i, j, n, m, k, l, o, p, tot, ans;
long long sum;
int query(long long x) {
    int l = 1, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (x >= t[mid] + 2)
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        t[i] = std::min(a[i].x + a[i].y,
                        std::min(a[i].x + a[i].z, a[i].y + a[i].z));
    }
    std::sort(t + 1, t + n + 1);
    for (i = 1; i <= n; i++) {
        int x;
        sum = 1ll * a[i].x + 1ll * a[i].y + 1ll * a[i].z;
        x = query(sum);
        if (std::max(a[i].x, std::max(a[i].y, a[i].z)) >= 2)
            x--;
        printf("%d ", x);
    }
}