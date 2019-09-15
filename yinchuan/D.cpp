#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        scanf("%d %d", &n, &m);
        double ans1 = n == 1 ? 1.0 : 0.5;
        double mm = (double)m;
        double ans2 = (m + 1.0) / (2.0 * m);
        printf("Case #%d: %lf %lf\n", tt, ans1, ans2);
    }
    return 0;
}