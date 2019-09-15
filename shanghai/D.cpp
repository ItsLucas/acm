#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010, maxm = 6010, mod = 1000000007;
int fpm(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1)
            ret = 1ll * ret * a % mod;
    return ret;
}
int fac[maxm], inv[maxm];
int ans[maxm], a[maxm], tp;
vector<int> p;
set<int> f[maxm];

bool np[maxm];
void dfs(int x, set<int>::iterator it, int the, int n) {
    1 if (it == f[n].end() || the == 1 || x < (*it)) {
        if (the > 1)
            return;
        int tmp = x, ret = inv[x];
        for (int i = 1; i <= tp; ++i) {
            tmp += a[i];
            ret = 1ll * ret * inv[a[i]] % mod;
        }
        ret = 1ll * fac[tmp] * ret % mod;
        ans[tmp] += ret;
        ans[tmp] %= mod;
        return;
    }
    for (int tmp = 1, num = *it, i = 1;; ++i) {
        tmp = tmp * num;
        if (x - num * i < 0 || the % tmp) {
            ++it;
            dfs(x, it, the, n);
            break;
        }
        a[++tp] = i;
        ++it;
        dfs(x - num * i, it, the / tmp, n);
        --it;
        --tp;
    }
}
void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[maxn - 1] = fpm(fac[maxn - 1], mod - 2);
    for (int i = maxn - 1; i; --i)
        inv[i - 1] = 1ll * inv[i] * i % mod;
    for (int i = 2; i < maxm; ++i) {
        if (!np[i]) {
            p.push_back(i);
            f[i].insert(i);
        }
        for (int j = 0, x; j < p.size(); ++j) {
            if (i * p[j] >= maxm)
                break;
            x = i * p[j];
            // cerr<<x<<endl;
            np[x] = 1;
            if (i % p[j] == 0) {
                f[x] = f[i];
                for (auto v : f[i]) {
                    f[x].insert(v * p[j]);
                }
                break;
            }
            f[x] = f[i];
            for (auto v : f[i]) {
                f[x].insert(v * p[j]);
            }
            f[x].insert(p[j]);
        }
    }
    set<int>::iterator it;
    for (int i = 2; i < maxm; ++i) {
        it = f[i].begin();
        dfs(i, it, i, i);
    }
}
int n;
void solve() {
    scanf("%d", &n);
    printf("%d\n", ans[n]);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    for (; T--;)
        solve();
    return 0;
}