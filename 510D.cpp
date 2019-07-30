#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 500050;
string dict = "AEIOUY";
double s[500050], dp[500050];
bool isv[256] = {false};

void init() {
    for (char c : dict) {
        isv[c] = true;
    }
}

int main() {
    init();
    s[1] = 1.0;
    for (int i = 2; i < N; i++) {
        s[i] = s[i - 1] + 1.0 / (double)i;
    }
    string ss;
    cin >> ss;
    int n = ss.size();
    dp[0] = s[n];
    for (int i = 0; i < n - 1; i++) {
        dp[i + 1] = dp[i] + s[n - i - 1] - s[i + 1];
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (isv[ss[i]])
            res += dp[i];
    }
    printf("%.6f\n", res); // WHY COUT GIVES ME INACCURATE VALUE?????????
    return 0;
}