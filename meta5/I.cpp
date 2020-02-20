#include <bits/stdc++.h>
using namespace std;
const int maxn = 1012010, mod = 1e9 + 7;
typedef long long ll;
int n;
int a[maxn];
ll fpm(ll a, ll b) {
    ll ret = 1ll;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) {
            ret = ret * a % mod;
        }
    return ret;
}
void solve() {
    // cin >> n;
    scanf("%d", &n);
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] < a[i - 1] || a[i] >= n || (i != 1) && a[i] == 0) {
            flag = 0;
        }
    }
    if (!flag || a[1] != 0 || a[n] != n - 1) {
        printf("%d\n", 0);
        return;
    }
    int cnt = 0;
    ll ans = 1;
    for (int i = 2, mx = 0, ls = 0, tim = 0; i <= n; ++i) {
        if (a[i] == ls) {
            ans = ans * (a[i] - i + 2) % mod;
        } else {
            ls = a[i];
            ans = ans * 2 % mod;
        }
    }
    printf("%lld\n", ans % mod);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();

    return 0;
}