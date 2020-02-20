#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m;
int a[maxn], b[maxn], c[maxn], B, C;
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", c + i);
    }
    for (int i = 1; i < n; ++i) {
        b[i] = abs(a[i] - a[i + 1]);
        //__gcd
    }
    B = b[1];
    for (int i = 2; i < n; ++i) {
        B = __gcd(B, b[i]);
    }
    C = c[1];
    for (int i = 2; i <= m; ++i) {
        C = __gcd(C, c[i]);
    }
    // cerr<<B<<" "<<C<<endl;
    if (B % C == 0)
        printf("YES\n");
    else
        puts("NO");
}
int main() {
    solve();

    return 0;
}