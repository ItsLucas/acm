#include <bits/stdc++.h>

using namespace std;

int main() {
    double v, n;
    cin >> v >> n;
    double tot = v * n;
    for (double i = 1; i <= 9; i += 1.0) {
        double frac = (double)i / 10.0f;
        double ans = tot * frac;
        ans = ceil(ans);
        if (i <= 8)
            cout << (long long)ans << " ";
        else
            cout << (long long)ans;
    }
    return 0;
}