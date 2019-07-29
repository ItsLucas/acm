#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2001;
ll maxx = 0;

vector<ll> make(vector<ll> a, ll n) {
    maxx = 0;
    vector<vector<ll>> L(n);
    vector<ll> msis(n);
    L[0].push_back(a[0]);
    msis[0] = a[0];
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            if ((a[i] >= a[j]) && (msis[i] <= msis[j])) {
                L[i] = L[j];
                msis[i] = msis[j];
            }
        }
        L[i].push_back(a[i]);
        msis[i] += a[i];
    }
    ll maxIndex = 0;
    maxx = msis[0];
    for (ll i = 1; i < n; i++)
        if (msis[i] > maxx) {
            maxx = msis[i];
            maxIndex = i;
        }
    ll pos = 0;
    vector<ll> tmp;
    for (ll i = 0; i < a.size(); i++) {
        if (a[i] != L[maxIndex][pos]) {
            tmp.push_back(a[i]);
        } else
            pos++;
    }
    return tmp;
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        ll n, k, ans = 0;
        scanf("%lld %lld", &n, &k);
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (ll i = 1; i <= k; i++) {
            a = make(a, a.size());
            ans += maxx;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
