#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[31];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll p = 1;
        bool flag = true;
        while (p < 1e16) {
            p *= k;
        }
        while (p > 0) {
            int cnt = 0;
            int p2 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] >= p) {
                    cnt++;
                    p2 = i;
                }
            }
            if (cnt > 1) {
                cout << "NO" << endl;
                flag = false;
                break;
            }
            if (p2 != 0)
                a[p2] -= p;
            p /= k;
        }
        if (flag == false)
            continue;
        ll maxx = 0;
        for (int i = 1; i <= n; i++) {
            maxx = max(a[i], maxx);
        }
        if (maxx != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}