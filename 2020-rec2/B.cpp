#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, x, m;
        cin >> n >> x >> m;
        int a = x;
        int b = x;
        for (int i = 1; i <= m; i++) {
            int l, r;
            cin >> l >> r;
            if (min(b, r) >= max(a, l)) {
                a = min(a, l);
                b = max(b, r);
            }
        }
        cout << b - a + 1 << endl;
    }
    return 0;
}