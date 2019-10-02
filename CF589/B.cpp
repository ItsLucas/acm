#include <bits/stdc++.h>

using namespace std;

static constexpr long long mod = 1e9 + 7;
int ro[1001];
int he[1001];
int grid[1001][1001];
int de[1001][1001]; // 1 white 2 black
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        cin >> ro[i];
        int tg;
        for (int j = 1; j <= min(w, ro[i] + 1); j++) {
            de[i][j] = (j > ro[i] ? 1 : 2);
            grid[i][j]++;
        }
    }
    bool flag = true;
    for (int i = 1; i <= w; i++) {
        cin >> he[i];
        int tg;
        for (int j = 1; j <= min(h, he[i] + 1); j++) {
            tg = (j > he[i] ? 1 : 2);
            if (de[j][i] == 1 && tg == 2 || de[j][i] == 2 && tg == 1) {
                // cout << i << " " << j << endl;
                flag = false;
            }
            grid[j][i]++;
        }
    }
    long long ans = 1;
    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            if (grid[i][j] == 0) {
                // cout << i << " " << j << endl;
                ans *= 2LL;
                ans %= mod;
            }
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}
/*
*
25 20
16 16 16 16 15 15 0 5 0 4 9 9 1 4 4 0 8 16 12 13 20 19 18 17 16
6 12 19 15 8 6 19 19 14 6 9 16 10 11 15 4 10 11 15 4
*/