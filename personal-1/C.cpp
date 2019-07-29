#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[200010];

ll powMod(ll a, ll b, ll MOD) {
    ll ans = 1;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

inline ll toint(const char &c) { return (ll)(c - '0'); }

int main() {
    ll MOD;
    cin >> s >> MOD;
    ll tmp = 0, ans;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        tmp = (tmp * 10 + toint(s[i])) % MOD;
    }
    ans = tmp;
    for (int i = 1; i < len; i++) {
        tmp = ((tmp * 10 - toint(s[i - 1]) * (powMod(10, len, MOD) - 1)) % MOD +
               MOD) %
              MOD;
        if (s[i] != '0') {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}