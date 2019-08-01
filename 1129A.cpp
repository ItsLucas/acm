
#include <bits/stdc++.h>

using namespace std;

inline int dist(int x, int y, int n) { return y >= x ? y - x : y - x + n; }

int t[20010];
int minn[20010] = {0x3f3f};

int main() {
    t[0] = 20000;
    memset(minn, 0x3f, sizeof(minn));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        t[a]++;
        minn[a] = (b > a ? min(minn[a], b - a) : min(minn[a], b - a + n));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = 0;
        for (int j = 1; j <= n; j++) {
            if (t[j] > 0) {
                ans = max(ans, dist(i, j, n) + n * (t[j] - 1) + minn[j]);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}