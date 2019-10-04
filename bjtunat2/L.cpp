#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
static constexpr int maxn = 100010;
int a[maxn], b[maxn];
map<ll, ll> up, down;
int main() {
    int n, m, y1, y2;
    cin >> n >> y1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m >> y2;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    ll ans = 2;
    for (ll len = 2; len <= 1e9; len *= 2LL) {
        up.clear();
        down.clear();
        for (int i = 1; i <= n; i++) {
            up[a[i] % len]++;
        }
        for (int i = 1; i <= m; i++) {
            down[b[i] % len]++;
        }
        for (int i = 1; i <= n; i++) {
            ans = max(ans, up[a[i] % len] + down[(a[i] + len / 2) % len]);
        }
        for (int i = 1; i <= m; i++) {
            ans = max(ans, down[b[i] % len] + up[(b[i] + len / 2) % len]);
        }
    }
    cout << ans << endl;
    return 0;
}