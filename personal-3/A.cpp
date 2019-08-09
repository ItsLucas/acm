#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static constexpr ll mod = 1e9 + 7;

// powered by qdd
// qdd tql
ll qk(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (a %= p; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll ans = (qk(27, n, mod) - qk(7, n, mod) + mod) % mod;
    cout << ans << endl;
}