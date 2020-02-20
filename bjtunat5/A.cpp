#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
struct dat {
    double a, b, c;
    dat(){};
    dat(double a, double b, double c) : a(a), b(b), c(c){};
    bool operator<(const dat &A) const {
        if (a != A.a)
            return a < A.a;
        else if (b != A.b)
            return b < A.b;
        return c < A.c;
    }
} tmp;
struct da {
    double a, b;
    da(){};
    da(double a, double b) : a(a), b(b){};
    bool operator<(const da &A) const {
        if (a != A.a)
            return a < A.a;
        return b < A.b;
    }
};
set<dat> S;
set<dat>::iterator it;
map<da, int> mp;

// map<dat,set<double> > mp;
// map<dat,set<double> >::iterator it;
ll ansa, ansb;
void solve() {
    double a, b, c, d, x1, x2, y1, y2;
    scanf("%d", &n);
    ansa = ansb = 0;
    S.clear();
    mp.clear();

    for (int i = 1; i <= n; ++i) {
        // scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        a = y2 - y1;
        b = x1 - x2;
        c = x2 * y1 - x1 * y2;
        d = __gcd(__gcd((ll)fabs(a), (ll)fabs(b)), (ll)fabs(c));
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        } else if (a == 0 && b < 0) {
            b = -b;
            c = -c;
        }
        a /= d;
        b /= d;
        c /= d;
        if (a == 0)
            ++ansa;
        else if (b == 0)
            ++ansb;
        else {
            int sz = S.size();
            S.insert(dat(a, b, c));
            if (sz == S.size() - 1) {
                ++mp[da(a, b)];
            }
        }
    }
    ll ans = 0;
    for (it = S.begin(); it != S.end(); ++it) {
        tmp = *it;
        b = tmp.a;
        a = tmp.b;
        a = -a;
        if (a < 0) {
            b = -b;
            a = -a;
        }
        if (mp.count(da(a, b)) != 0) {
            ans += mp[da(a, b)];
        }
    }
    ans >>= 1;
    printf("%lld\n", ans + (1ll * ansa * ansb));
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}