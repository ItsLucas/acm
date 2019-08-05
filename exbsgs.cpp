#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define mod 99991
const int maxn = 1000007;
int h[maxn], ne[maxn], bj[maxn], tot;
ll has[maxn];
void add(ll x, ll j) {
    int kl = x % maxn;
    tot++;
    bj[tot] = j;
    has[tot] = x;
    ne[tot] = h[kl];
    h[kl] = tot;
}
ll find(ll x) {
    ll kl = x % maxn, i;
    for (i = h[kl]; i != -1; i = ne[i])
        if (has[i] == x)
            return bj[i];
    return -1;
}
ll bsgs(ll a, ll b, ll n) { // a^x=b(mod n)
    if (b == 1)
        return 0;
    memset(h, -1, sizeof(h));
    ll m = ceil(sqrt((double)n)), q = 1, j, x = 1;
    for (ll i = 0; i < m; i++) {
        add((q * b) % n, i);
        q = (q * a) % n;
    }
    for (ll i = m;; i += m) {
        x = (x * q) % n;
        j = find(x);
        if (j != -1)
            return i - j;
        if (i > n)
            break;
    }
    return -1;
}
int main() {
    ll a, b, p, ans;
    while (1) {
        scanf("%lld%lld%lld", &a, &p, &b);
        if (!a && !b && !p)
            break;
        memset(h, -1, sizeof(h));
        tot = 0;
        ans = bsgs(a, b, p);
        if (ans == -1)
            puts("No Solution");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
