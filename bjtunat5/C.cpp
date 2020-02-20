#include <bits/stdc++.h>

using namespace std;

char a[100010], b[100010];
int dp[1010][1010];
int ans;

int main() {
    int n;
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    n = strlen(a + 1);
    int m = min(n, 1000);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            while (a[i + dp[i][j] + 1] == b[j + dp[i][j] + 1] &&
                   i + dp[i][j] + 1 <= n && j + dp[i][j] + 1 <= n) {
                dp[i][j]++;
            }
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << (100 * ans >= 99 * n ? "Long lost brothers D:" : "Not brothers :(")
         << endl;
    return 0;
}