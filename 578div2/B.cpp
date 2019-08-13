#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll b[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t, n, m, k;
    cin >> t;
    while (t-- > 0) {
        memset(b, 0, sizeof(b));
        cin >> n >> m >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> b[i];
        }
        ll i = 1;
        bool flag = true;
        while (i < n) {
            if (b[i] >= b[i + 1]) {     // can make the jump
                ll diff = b[i + 1] - k; // decrease hi to next,and jump
                ll re = b[i] - diff;
                m += min(b[i], re);
                // cout << "Took dm = " << b[i] - diff << endl;
            } else if (b[i + 1] - b[i] <= k) { // 6 10 k=6
                ll diff = b[i + 1] - k;        // decrease hi to next,and jump
                ll re = b[i] - diff;
                m += min(b[i], re);
                // cout << "Took dm = " << b[i] - diff << endl;
            } else { // can't
                ll diff = b[i + 1] - k;
                ll diff2 = diff - b[i];
                if (m >= diff2) {
                    m -= diff2;
                } else {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }
            i++;
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }
    return 0;
}