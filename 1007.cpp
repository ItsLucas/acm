#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
static constexpr ll maxn = 100050;
static constexpr ll mod = 998244353;
ll f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    ll N = 100001;
    f[1] = 1;
    f[2] = 1;
    f[3] = 1;
    f[4] = 2;
    for (ll i = 5; i <= N; i++) {
        f[i] = f[i - 1] + f[i - 3];
        f[i] %= mod;
    }
    ll t;
    cin >> t;
    while (t-- > 0) {
        ll n, x, y, xx, yy;
        cin >> n >> x >> y;
        if (x == 1)
            xx = 1;
        else
            xx = x + 1;
        if (y == n)
            yy = n;
        else
            yy = y - 1;
        cout << f[yy - xx + 1] << "\n";
    }
    return 0;
}