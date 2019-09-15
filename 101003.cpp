#include <bits/stdc++.h>
using namespace std;
int T, n;
double p[10005];
int maxn;
void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        if (p[maxn] < p[i])
            maxn = i;
    }
    if (p[maxn] >= 0.5) {
        printf("%.12lf\n", p[maxn]);
        return;
    } else {
        double x;
        x = p[1];
        for (int i = 2; i <= n; i++) {
            x = (1 - x) * p[i] + (1 - p[i]) * x;
        }
        printf("%.12lf\n", x);
    }
    return;
}
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        work();
        maxn = 0;
    }
}