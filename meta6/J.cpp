#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 1510, maxn = 2e5 + 10;
int n, m;
ll s0[maxm][maxm], s1[maxm][maxm], s2[maxm][maxm];
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1, xl, xr, yl, yr; i <= n; ++i) {
        scanf("%d%d%d%d", &xl, &xr, &yl, &yr);
        xr++;
        yr++;
        s0[xl][yl] += 1;
        s0[xr][yr] -= 1;
        s1[xl][yl] += i;
        s2[xr][yr] -= i;
        s2[xl][yl] += 1ll * i * i;
        s2[xr][yr] -= 1ll * i * i;
    }
    vector<ll> s(n + 1);
    map<pair<int, int>, ll> mp;
    ll tot = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j) {
            s0[i][j] += s0[i - 1][j] + s0[i][j - 1] - s0[i - 1][j - 1];
            s1[i][j] += s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1];
            s2[i][j] += s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1];
            if (s0[i][j] == 0)
                continue;
            ++tot;
            if (s0[i][j] > 2)
                continue;
            if (s0[i][j] == 1)
                s[s1[i][j]]++;
            if (s0[i][j] == 2) {
                ll delty = (long long)sqrt(2 * s2[i][j] - s1[i][j] * s1[i][j]);

                int x = abs(s1[i][j] + delty) / 2,
                    y = abs(s1[i][j] - delty) / 2;
                // cerr << " " << x << " " << y << endl;
                if (x > y)
                    swap(x, y);
                mp[make_pair(x, y)]++;
            }
        }
    ll m1 = max(s[1], s[2]), m2 = min(s[1], s[2]);
    for (int i = 3; i <= n; ++i) {
        if (s[i] > m1) {
            m1 = s[i];
            m2 = m1;
        }
    }
    ll tmp = m1 + m2;
    for (auto &e : mp) {
        tmp = max(s[e.first.first] + s[e.first.second] + e.second, tmp);
    }
    printf("%lld\n", tot - tmp);
}
int main() {
    int T;
    scanf("%d", &T);
    for (; T--;)
        solve();

    return 0;
}