#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N = 2e5 + 5;
ld R, x, y, x2, y2;
ld dis(ld x, ld y, ld a, ld b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> x >> y >> x2 >> y2;
    ld d = dis(x, y, x2, y2);
    if (d >= R) {
        cout << fixed << setprecision(8) << x << ' ' << y << ' ' << R << endl;
        return 0;
    }
    ld r = (d + R) * 0.5;
    ld a = (x - x2) * (R - r) / d + x;
    ld b = (y - y2) * (R - r) / d + y;
    if (x == x2 && y == y2)
        a = x + r, b = y;
    cout << fixed << setprecision(8) << a << ' ' << b << ' ' << r << endl;
    return 0;
}
