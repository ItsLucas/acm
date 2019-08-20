#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1e6 + 10;

int dp[maxn], sum[maxn], s1[maxn], s2[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n) {
        int l = 0, r = 0;
        dp[0] = -(0x7ffffffe);
        sum[0] = 0;
        while (n-- > 0) {
            char c;
            cin >> c;
            switch (c) {
            case 'I': {
                cin >> s1[++l];
                sum[l] = sum[l - 1] + s1[l];
                dp[l] = max(dp[l - 1], sum[l]);
                break;
            }
            case 'D': {
                l--;
                break;
            }
            case 'L': {
                if (l != 0) {
                    s2[++r] = s1[l--];
                }
                break;
            }
            case 'R': {
                if (r != 0) {
                    s1[++l] = s2[r--];
                    sum[l] = sum[l - 1] + s1[l];
                    dp[l] = max(dp[l - 1], sum[l]);
                }
                break;
            }
            default: {
                int a;
                cin >> a;
                cout << dp[a] << endl;
                break;
            }
            }
        }
    }
}