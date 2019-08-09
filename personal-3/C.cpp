#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100010], b[100010];

inline bool cmp(ll a, ll b) { return a > b; }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1, cmp);
    ll ans = 0;
    for (int i = 1; i <= min(n, m); i++) {
        b[i] > a[i] ? ans += b[i] - a[i] : ans = ans;
    }
    cout << ans << endl;
    return 0;
}