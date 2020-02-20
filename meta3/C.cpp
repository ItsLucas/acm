#include <bits/stdc++.h>
#define N 11000000
bool f[N];
long long i, j, n, m, k, l, o, ans;
int main() {
    scanf("%d%d", &n, &m);
    k = std::min(n * 2, m);
    o = 0;
    f[0] = true;
    for (i = 1; i <= k; i++) {
        o = (o + i) % n;
        f[o] = true;
    }
    for (i = 0; i < n; i++)
        if (f[i])
            ans++;
    printf("%d", ans);
}