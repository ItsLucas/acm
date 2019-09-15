#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct coinp {
    bool vis = false;
    ll val1, val2;
    inline bool operator<(const coinp &c) const { return val1 < c.val1; }
} coins[100010];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        ll x, y;
        scanf("%d", &n);
        ll maxx = -1;
        ll tot = 0;
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &x, &y);
            maxx = max(x, maxx);
            tot += x;
            tot += y;
            coins[i] = {0, x, y};
        }
        int now = 1;
        sort(coins + 1, coins + n + 1);
        printf("%lld ", maxx);

        for (int i = 2; i <= 2 * n - 1; i++) {
            // option1
            ll o1f = re;
            ll o1s = coins[now + 1].val1;
            // option2
            ll o2f =
        }
        printf("%lld\n", tot);
    }
}