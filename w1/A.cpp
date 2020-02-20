#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[15], b[15];

int main() {
    for (int i = 1; i <= 14; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= 14; i++) {
        copy(a + 1, a + 15, b + 1);
        ll cnt = b[i];
        b[i] = 0;
        for (int j = 1; j <= 14; j++) {
            b[j] += cnt / 14;
        }
        cnt %= 14;
        int pos = i + 1;
        while (cnt--) {
            if (pos > 14)
                pos = 1;
            b[pos++]++;
        }
        ll t = 0;
        for (int j = 1; j <= 14; j++) {
            if (b[j] & 1)
                continue;
            t += b[j];
        }
        ans = max(t, ans);
    }
    cout << ans << endl;
    return 0;
}