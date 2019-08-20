#include <bits/stdc++.h>

using namespace std;

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
        cin >> a;
        int b;
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            cin >> b;
            if (b % 2 != a % 2) {
                flag = false;
            }
        }
        if (flag) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}