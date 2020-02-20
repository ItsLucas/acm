#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        if (n <= 5) {
            cout << -1 << endl;
            continue;
        } else {
            if (n & 1) {
                cout << 3 << " " << n - 3 << endl;
                continue;
            } else {
                cout << 2 << " " << n - 2 << endl;
                continue;
            }
        }
    }
    return 0;
}