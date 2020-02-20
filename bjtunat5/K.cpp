#include <bits/stdc++.h>
using namespace std;
int n, T;
void solve() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        if (n == 1 || n == 2)
            puts("0");
        else if (n == 3)
            puts("2");
        else {
            int ans;
            if (n % 3 == 1)
                ans = 1;
            else if (n % 3 == 0)
                ans = 2;
            else
                ans = 1;
            ans = (n - 1) / 3 * 2 + ans;
            cout << ans << endl;
        }
    }
}
int main() {
    solve();
    return 0;
}
