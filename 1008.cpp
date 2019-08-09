#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll kth(ll n, ll m) {
    int cnt = 0;
    ll nn = n;
    while (cnt != m) {
        nn++;
        if (gcd(nn, n) == 1) {
            cnt++;
        }
    }
    return nn;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        ll k, m;
        scanf("%lld %lld", &k, &m);
        ll ans = -1;
        ll l = k - m * 69;
        ll r = k + m * 69;
        for (ll n = max(1LL, l); n <= r; n++) {
            if (gcd(n + (n ^ k), n) != 1) {
                continue;
            }
            if (((kth(n, m) - n) ^ n) == k) {
                ans = n;
                break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}