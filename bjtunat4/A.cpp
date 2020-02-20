#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n;
double l[maxn], X, Y, Ll, Rl;
pair<double, double> Ans[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", l + i);
    }
    scanf("%lf%lf", &X, &Y);
    if (n == 1) {
        printf("%.3lf ", l[1] * X / sqrt(X * X + Y * Y));
        printf("%.3lf\n", l[1] * X / sqrt(X * X + Y * Y));
    }
    int mxl = l[1], id = 1;
    for (int i = 2; i <= n; ++i) {
        if (mxl < l[i])
            mxl = l[id = i];
    }
    for (int i = 1; i <= id - 1; ++i) {
        Ll += l[i];
    }
    for (int i = id + 1; i <= n; ++i) {
        Rl += l[i];
    }
    if (Ll + Rl + l[id] < sqrt(X * X + Y * Y)) {
        double ansx = 0, ansy = 0;
        for (int i = 1; i <= n; ++i) {
            ansx += l[i] * X / sqrt(X * X + Y * Y);
            ansy += l[i] * Y / sqrt(X * X + Y * Y);
            printf("%.3lf ", ansx);
            printf("%.3lf\n", ansy);
        }
    } else if (Ll + Rl + sqrt(X * X + Y * Y) < l[id]) {
        double ansx = 0, ansy = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == id) {
                ansx += l[i] * X / sqrt(X * X + Y * Y);
                ansy += l[i] * Y / sqrt(X * X + Y * Y);
            } else {
                ansx -= l[i] * X / sqrt(X * X + Y * Y);
                ansy -= l[i] * Y / sqrt(X * X + Y * Y);
            }
            printf("%.3lf ", ansx);
            printf("%.3lf\n", ansy);
        }
    } else {
        double COS = (Rl * Rl + Ll * Ll - l[id] * l[id]) / 2 * Rl * Ll;
        double beta = 0;
        double SIN = sqrt(1 - COS * COS);
        for (int i = 1; i < id; ++i) {
            Ans[i].first -= l[i] * X / sqrt(X * X + Y * Y);
            Ans[i].second -= l[i] * Y / sqrt(X * X + Y * Y);
        }
        double C = X / sqrt(X * X + Y * Y), S = Y / sqrt(X * X + Y * Y);
        double cc = C * COS - S * SIN;
        double ss = S * COS + C * SIN;
        Ans[n].first = X;
        Ans[n].second = Y;
        for (int i = n - 1; i >= id; --i) {
            // cerr<<l[i+1]<<endl;
            Ans[i].first -= l[i + 1] * cc;
            Ans[i].second -= l[i + 1] * ss;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%.3lf %.3lf\n", Ans[i].first, Ans[i].second);
        }
    }
}
int main() {
    solve();
    return 0;
}