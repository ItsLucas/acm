#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    double ans = n;
    for (int i = 1; i < n; ++i) {
        ans -= pow(1.0 * i / n, m);
    }
    cout.setf(ios::fixed);
    cout << setprecision(12) << ans << endl;
    return 0;
}