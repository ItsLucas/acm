#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a;
        long long tot = 0;
        cin >> a;
        tot += a;
        int cd = a;
        for (int i = 2; i <= n; i++) {
            cin >> a;
            tot += a;
            cd = __gcd(cd, a);
        }
        cout << tot << " " << cd << '\n';
    }
    return 0;
}