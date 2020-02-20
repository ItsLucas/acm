#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1001;

int x[maxn], y[maxn], h[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    int l1 = 2e9, l2 = 2e9, r1 = -2e9, r2 = -2e9;
    for (int i = 1; i <= n; i++) {
        l1 = min(l1, x[i] - h[i]);
        r1 = max(r1, x[i] + h[i]);
        l2 = min(l2, y[i] - h[i]);
        r2 = max(r2, y[i] + h[i]);
    }
    int X = (l1 + r1) / 2;
    int Y = (l2 + r2) / 2;
    int h1 = max(X - l1, Y - l2);
    int h2 = max(r1 - X, r2 - Y);
    cout << X << " " << Y << " " << max(h1, h2) << endl;
    return 0;
}