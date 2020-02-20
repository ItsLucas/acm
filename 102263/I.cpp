#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int n;
int a[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    ll ans = a[n] - a[1], tmp = ans;
    printf("%lld ", ans);
    for (int i = 3; i <= n; i++) {
        if (i & 1) {
            ans = ans + tmp;
        } else
            ans = (ans + tmp) + a[n - i / 2 + 1] - a[i / 2],
            tmp += a[n - i / 2 + 1] - a[i / 2];
        printf("%lld ", ans);
    }
}
int main() {
    solve();

    return 0;
}