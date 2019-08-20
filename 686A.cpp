#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;
    char op;
    ll d, kid = 0, ice = 0;
    ice += x;
    for (ll i = 1; i <= n; i++) {
        cin >> op >> d;
        switch (op) {
        case '+': {
            ice += d;
            break;
        }
        case '-': {
            ice >= d ? ice -= d : kid++;
            break;
        }
        default:
            break;
        }
    }
    cout << ice << " " << kid << endl;
    return 0;
}