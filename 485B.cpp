#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long x, y;
    long long maxx = -INT_MAX, minx = INT_MAX, maxy = -INT_MAX, miny = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        maxx = max(maxx, x);
        minx = min(minx, x);
        maxy = max(maxy, y);
        miny = min(miny, y);
    }
    long long xx = maxx - minx;
    long long yy = maxy - miny;
    cout << max(xx, yy) * max(xx, yy) << endl;
    return 0;
}