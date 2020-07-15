#include <bits/stdc++.h>

using namespace std;

long long dp[10001];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10001; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int n;
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}