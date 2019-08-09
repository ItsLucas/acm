#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100010];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            printf("%lld ", a[i]);
        }
        printf("\n");
        ll aa = 0;
        ll bb = 0;
        bool flag = 0;
        for (int i = n; i >= 1; i--) {
            if (flag == 0) {
                aa += a[i];
            } else {
                bb += a[i];
            }
            flag = !flag;
        }
        printf("%lld %lld\n", aa, bb);
    }
    return 0;
}