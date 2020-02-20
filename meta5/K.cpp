#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e6 + 10;
ll sum;
int a[maxn], n, m;
void solve() {
    scanf("%d%d", &n, &m);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum += a[i];
    }
    // sum+=m;
    for (int i = 1; i <= n; ++i) {
        printf("%.7lf ", 1.0 * a[i] / sum * (sum + m));
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();

    return 0;
}