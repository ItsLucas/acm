#include <bits/stdc++.h>

using namespace std;

const int maxn = 5001;
const int inf = 0x3f3f3f3f;
bool vis[maxn][maxn];
int dp[maxn];
int a[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = i; j <= n; j++) {
            if (a[j] < m)
                cnt++;
            int mid = (j + 2 - i) >> 1;
            vis[i][j] = (cnt < mid ? 1 : 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = -inf;
        for (int j = 0; j < i; j++) {
            if (vis[j + 1][i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << max(dp[n], 0) << endl;
    return 0;
}