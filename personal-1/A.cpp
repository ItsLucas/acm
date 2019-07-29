#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    int ans = 0;
    cin >> n >> m;
    if (m <= n) {
        cout << n - m << endl;
        return 0;
    } else {
        while (n < m) {
            if (m % 2 != 0) {
                m++;
                ans++;
            }
            m /= 2;
            ans++;
        }
        ans += n - m;
        cout << ans << endl;
    }
    return 0;
}
