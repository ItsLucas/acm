#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p, q, n;
inline int fpm(int a, int b) {
    int ret = 1ll;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ret = ret * a;
    return ret;
}
inline int calc(int p, int n, int P) {
    if (n <= 0)
        return 1;
    return (P - 1) / __gcd(p, P - 1) * (fpm(P, n - 1)) /
               __gcd(p, fpm(P, n - 1)) +
           calc(p, n - p, P);
}
inline void solve() {
    cin >> p >> q >> n;
    // cout<<clock()<<endl;
    int ans = 1;
    if (n == 2) {
        puts("2");
        return;
    }
    for (int i = 2, tmp, ie = (int)sqrt(n); i <= ie; ++i) {
        if (n % i == 0) {
            tmp = 0;
            if (__gcd(p, i) == 2 && __gcd(n, i * i) == 4)
                --tmp;
            while (n % i == 0) {
                n /= i;
                ++tmp;
            }
            ans = ans * calc(p, tmp, i);
        }
    }
    if (n != 1)
        ans = ans * calc(p, 1, n);
    cout << ans << endl;
    // cout<<clock()<<endl;
}
int main() {
    solve();
    return 0;
}