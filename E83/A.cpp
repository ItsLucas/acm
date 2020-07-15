#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        cout << (n % m == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}