#include <bits/stdc++.h>

using namespace std;

long long a[100010];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        long long tmp = 0, ans = 0, l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                tmp += a[r--] - a[l++];
                ans += tmp;
            } else
                ans += tmp;
            if (i == n - 1)
                cout << ans;
            else
                cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}