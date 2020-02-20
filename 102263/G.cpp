#include <bits/stdc++.h>
using namespace std;
int n;
double ans;
void solve() {
    scanf("%d", &n);
    for (int i = n; i; --i) {
        ans += 1.0 * i * (i - 1) / n;
    }
    printf("%lf", ans);
}
int main() {
    solve();

    return 0;
}