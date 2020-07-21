#include <bits/stdc++.h>

using namespace std;

int a[31][31];
int f[62][2];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i + j][a[i][j]]++;
            }
        }
        int ans = 0;
        int p = n + m - 2;
        for (int i = 0; i <= p; i++) {
            int x = p - i;
            if (i <= x)
                continue;
            ans += min(f[i][0] + f[x][0], f[i][1] + f[x][1]);
        }
        cout << ans << endl;
    }
    return 0;
}