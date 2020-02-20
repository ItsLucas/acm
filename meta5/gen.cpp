#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("B.in", "w", stdout);
    int T = 1, n, m;
    // scanf("%d",a+i);
    printf("%d\n", T);

    n = 100, m = 16;
    printf("%d %d\n", n, m);
    for (int i = 1, ls; i < n; ++i) {
        printf("%d %d\n", (i - 1) * 100, i * 100 - 1);
    }
    printf("%d %d\n", (n - 1) * 100, (int)pow(2, 16) - 1);
    return 0;
}