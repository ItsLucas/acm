#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> getf(ll x) {
    vector<ll> v;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            v.push_back(i);
            x /= i;
        }
    }
    if (x != 1)
        v.push_back(x);
    return v;
}

int main() {
    ll x, y;
    cin >> x >> y;
    cout << x * y << endl;
    vector<ll> v = getf(x * y);
    for (ll i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}