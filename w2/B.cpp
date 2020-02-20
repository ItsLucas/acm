#include <bits/stdc++.h>

using namespace std;

struct loc {
    int x, y;
    bool operator<(const loc &a) const {
        return x < a.x || (!(a.x < x) && y < a.y);
    }
};

map<int, int> x, y;
map<loc, int> b;

int main() {
    int n, xx, yy;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xx >> yy;
        x[xx]++, y[yy]++;
        b[{xx, yy}]++;
        ans = ans + (long long)(x[xx] - 1) + (long long)(y[yy] - 1) -
              (long long)(b[{xx, yy}] - 1);
    }
    cout << ans << endl;
    return 0;
}
