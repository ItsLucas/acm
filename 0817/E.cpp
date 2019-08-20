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
        if (n == 2 || n == 3) {
            cout << "second" << '\n';
        } else {
            cout << "first" << '\n';
        }
    }
    return 0;
}