#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500005;
const int mod = 1e9 + 7;

int qp(ll a, int n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

int f[maxn];
int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, Q, p, q, a, x, l, r;
        scanf("%d %d", &n, &Q);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &p, &q, &x, &a);
            ll tmp = (f[i - 1] - f[x - 1] + mod) % mod;
            f[i] = (tmp + a) % mod * q % mod * qp(p, mod - 2, mod) % mod;
            f[i] = (f[i] - tmp + mod) % mod;
            f[i] = (f[i - 1] + f[i]) % mod;
        }
        while (Q-- > 0) {
            scanf("%d %d", &l, &r);
            printf("%d\n", (f[r - 1] - f[l - 1] + mod) % mod);
        }
    }
    return 0;
}