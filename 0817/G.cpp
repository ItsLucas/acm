#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll fx[21], fy[21];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t-- > 0) {
        ll n, m, k;
        cin >> n >> m >> k;
        for (ll i = 0; i < k; i++) {
            cin >> fx[i] >> fy[i];
        }
        ll ans = (n * (n + 1) / 2) * (m * (m + 1) / 2);
        for (ll i = 1; i < (1 << k); i++) {
            ll ii = i;
            ll cnt = 0;
            while (ii) {
                cnt += ii & 1;
                ii /= 2;
            }
            ll maxx = 0, maxy = 0, minx = 1e18, miny = 1e18;
            for (ll j = 0; j < k; j++) {
                if ((i >> j) & 1) {
                    maxx = max(maxx, fx[j]);
                    minx = min(minx, fx[j]);
                    maxy = max(maxy, fy[j]);
                    miny = min(miny, fy[j]);
                }
            }
            ll sum = minx * miny * (n - maxx + 1) * (m - maxy + 1);
            ans += (cnt & 1 ? -sum : sum);
        }
        cout << ans << endl;
    }
    return 0;
}