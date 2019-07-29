#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static constexpr double eps = 1e-9;
double x, y, m;

inline double f(double a, double b) { return 1.0f * a * (1.0f / (b * 1.0f)); }

int cx(double ti) {
    int l = 0, r = x, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid, x) > ti)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}

int cy(double ti) {
    int l = 0, r = y, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (f(mid, y) > ti)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}

int main() {
    int n, t1, h;
    double l, r, mid;
    int xx, yy;
    scanf("%d %lf %lf", &n, &x, &y);
    while (n-- > 0) {
        scanf("%lf", &m);
        t1 = m / (x + y);
        m -= (x + y) * t1;
        l = 0;
        r = 1;
        for (int i = 1; i <= 185; i++) {
            mid = (l + r) / 2.0;
            xx = cx(mid);
            yy = cy(mid);
            if (xx + yy >= m)
                r = mid;
            else
                l = mid;
        }
        double xxd = floor(mid * x + eps);
        double yyd = floor(mid * y + eps);
        // cout << xxd * y << " " << yyd * x << endl;
        if (xxd * y == yyd * x)
            printf("Both\n");
        else if (xxd * y > yyd * x)
            printf("Vanya\n");
        else if (xxd * y < yyd * x)
            printf("Vova\n");
    }
    return 0;
}
