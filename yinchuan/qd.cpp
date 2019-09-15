#include <bits/stdc++.h>

using namespace std;

char a[60], b[60], c[60];

int main() {
    int n, m, t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", c);
        int diff = a[0] < b[0] ? b[0] - a[0] : b[0] + 26 - a[0];
        // printf("diff=%d\n", diff);
        for (int i = 0; i < m; i++) {
            if (c[i] - diff < 'A') {
                c[i] = c[i] - diff + 26;
            } else {
                c[i] -= diff;
            }
        }
        printf("Case #%d: %s\n", tt, c);
    }
    return 0;
}