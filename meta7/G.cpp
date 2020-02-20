#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
static constexpr ll mod = 1e9 + 7;
ll a, b, c, d;
ll fpm(ll a, ll b) {
    ll ret = 1ll;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) {
            ret = ret * a % mod;
        }
    return ret;
}
long long inv(long long a) { return fpm(a, mod - 2ll); }
ll f(int x) {
    return a * fpm(x, 4) % mod + b * fpm(x, 3) % mod + c * fpm(x, 2) % mod +
           b * x % mod;
}
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a = 375ll * inv(9000) % mod, b = inv(4), c = 4125ll * inv(9000) % mod;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        cout << f(t) % mod << '\n';
    }
    return 0;
}