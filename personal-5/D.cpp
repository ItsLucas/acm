#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static constexpr ll maxn = (1 << 18) + 10;

ll n, m;
ll s[21];
ll f[maxn][105];
char ch[20];
vector<bool> vis;

int main() {
    scanf("%s %lld", &ch, &m);
    n = strlen(ch);
    f[0][0] = 1;
    ll e = (1 << n);
    for (ll i = 0; i < e; i++) {
        for (ll j = 0; j < m; j++) {
            vis.assign(21, 0);
            for (ll k = 0; k < n; k++) {
                ll x = ch[k] - '0';
                if ((i & (1 << k)) || (i == 0 && x == 0) || (vis[x])) {
                    continue;
                }
                vis[x] = 1;
                f[i | (1 << k)][(j * 10 + x) % m] += f[i][j];
            }
        }
    }
    e--;
    printf("%lld\n", f[e][0]);
}