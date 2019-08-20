#include <bits/stdc++.h>
using namespace std;
const int MAXN = 114;
int w[MAXN];

int dfs(int w, int nu50, int nu20, int nu10) {
    if (w == 0)
        return 1;
    if (w < 0)
        return 0;
    if (nu50) {
        for (int n50 = 0; n50 <= nu50; n50++)
            if (dfs(w - n50 * 50, 0, nu20, nu10))
                return 1;
        return 0;
    }
    if (nu20) {
        for (int n20 = 0; n20 <= nu20; n20++)
            if (dfs(w - n20 * 20, 0, 0, nu10))
                return 1;
        return 0;
    }
    if (nu10) {
        for (int n10 = 0; n10 <= nu10; n10++)
            if (dfs(w - n10 * 10, 0, 0, 0))
                return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, flag = 1;
        int num100_ = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);

            num100_ = max(max((w[i] / 100) - 1, num100_), 0);
            // w[i]%=200;
            if (w[i] % 10)
                flag = 0;
        }
        if (flag == 0) {
            printf("-1\n");
            continue;
        }
        int ans = 0x7fefefef;
        for (int i = num100_; i <= num100_ + 1; i++)
            for (int j = 0; j <= min(1, ans - i); j++)
                for (int k = 0; k <= min(4, ans - i - j); k++)
                    for (int l = 0; l <= min(9, ans - i - j - k); l++) {
                        int flag1 = 1;
                        for (int ii = 0; ii < n; ii++) {
                            int temp = w[ii];
                            temp -= min(temp / 100, i) * 100;
                            int flag_1 = dfs(temp, j, k, l);
                            if (w[ii] > 100)
                                flag_1 = flag_1 || dfs(temp + 100, j, k, l);
                            if (!flag_1) {
                                flag1 = 0;
                                break;
                            }
                        }
                        if (flag1)
                            ans = min(ans, i + j + k + l);
                    }
        printf("%d\n", ans);
    }
}