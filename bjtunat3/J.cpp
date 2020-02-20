#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 300010;
int dp[maxn], a[maxn];
bool vis[maxn];

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[0] = -1e9;
    dp[0] = 0;
    a[n + 1] = 2e9;
    for (int i = 1; i <= n; i++) {
        if ((i >= 2) && (dp[i - 2] >= 0) && (a[i + 1] - a[i] > 1000) &&
            (a[i] - a[i - 1] < 2000) && (a[i - 1] - a[i - 2] > 1000)) {
            vis[i] = vis[i - 2];
            dp[i] = dp[i - 2] + 1;
        }
        if ((i >= 3) && (dp[i - 3] >= 0) && (a[i + 1] - a[i] > 1000) &&
            (a[i] - a[i - 1] < 2000 && a[i - 1] - a[i - 2] < 2000) &&
            (a[i - 2] - a[i - 3] > 1000)) {
            vis[i] = vis[i - 3];
            if (dp[i] > 0) {
                if (dp[i] != dp[i - 3])
                    vis[i] = 1;
            } else {
                dp[i] = dp[i - 3];
                vis[i] = vis[i - 3];
            }
        }
    }
    if (dp[n] == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (vis[n] == 1) {
        cout << "Ambiguous" << endl;
        return 0;
    }
    cout << "Cars without trailers: " << dp[n] << endl;
    cout << "Cars with trailers: " << (n - dp[n] * 2) / 3 << endl;
    return 0;
}
