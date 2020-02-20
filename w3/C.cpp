#include <bits/stdc++.h>

using namespace std;

bool G[2001][2001];
int x[2001][2001], y[2001][2001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            c == '*' ? G[i][j] = 0 : G[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            x[i][j] = x[i][j - 1] + G[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            y[i][j] = y[i][j - 1] + G[j][i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            if (x[i][j] - x[i][j - k] == k)
                ans++;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = k; j <= n; j++) {
            if (y[i][j] - y[i][j - k] == k) {
                ans++;
            }
        }
    }
    cout << (k == 1 ? ans / 2 : ans) << endl;
    return 0;
}