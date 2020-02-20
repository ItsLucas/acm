#include <bits/stdc++.h>
#define pi acos(-1.0)
const double eps = 1e-12;
double al, be, ans;
int n;
void solve() {
    scanf("%d", &n);
    for (int a, b, r, ang; n--;) {
        scanf("%d%d%d%d", &a, &b, &r, &ang);
        al = atan(1.0 * b / (a + r)) * 180 / pi;
        be = ang; //(1.0*ang*pi/180);
        if (al - be > eps) {
            al = al - be;
            ans = cos(al * pi / 180) *
                      sqrt(1.0 * b * b + 1.0 * (a + r) * (a + r)) -
                  r;
            printf("%.8lf\n", ans);
        } else {
            ans = sqrt(1.0 * b * b + 1.0 * (a + r) * (a + r));
            ans -= r;
            printf("%.8lf\n", ans);
        }
    }
}
int main() {
    solve();

    return 0;
}