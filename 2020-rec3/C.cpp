#include <bits/stdc++.h>

using namespace std;

inline long double dis(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
    long double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    long double d = dis(x1, y1, x2, y2);
    if (d >= r) {
        cout << setprecision(15) << x1 << " " << y1 << " " << r << endl;
    } else {
        long double r2 = (d + r) / 2.0f;
        long double a = (x1 - x2) * (r - r2) / d + x1;
        long double b = (y1 - y2) * (r - r2) / d + y1;
        if (x1 == x2 && y1 == y2)
            a = x1 + r2, b = y1;
        cout << setprecision(15) << a << " " << b << " " << r2 << endl;
    }
    return 0;
}