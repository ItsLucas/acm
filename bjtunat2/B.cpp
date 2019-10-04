#include <bits/stdc++.h>
#define N 210000
struct sl {
    int l, r;
} a[N];
int sum[N], i, j, n, m, k, l, o, p, maxn, num, mid, x, r;
int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
        if (i >= 2)
            sum[i] = sum[i - 1] + a[i].l - a[i - 1].r;
    }
    for (i = 1; i <= n; i++) {
        if (sum[n] - sum[i] < m) {
            num = a[n].r - a[i].l + m - (sum[n] - sum[i]);
        } else {
            l = i;
            r = n;
            while (r - l > 5) {
                mid = (l + r) >> 1;
                if (sum[mid] - sum[i] < m)
                    x = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            for (j = r; j >= l; j--)
                if (sum[j] - sum[i] < m) {
                    x = j;
                    break;
                }
            num = a[x].r - a[i].l + m - (sum[x] - sum[i]);
        }
        maxn = std::max(maxn, num);
    }
    printf("%d", maxn);
}