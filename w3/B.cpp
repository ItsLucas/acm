#include <bits/stdc++.h>

using namespace std;

const int maxn = 5001;

bool f[maxn][maxn], g[maxn][maxn];
char s[maxn + 5];

inline bool even(int x) { return x & 1; }

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int l = 1; l <= n; l++) {
        int p = 0;
        bool flag = true;
        for (int r = l; r <= n; r++) { //?+(>=)
            if (s[r] == ')')
                p--;
            else
                p++;
            if (p < 0)
                flag = false;
            f[l][r] = flag;
        }
    }
    for (int r = 1; r <= n; r++) { //?+)>=(
        int p = 0;
        bool flag = true;
        for (int l = r; l >= 1; l--) {
            if (s[l] == '(')
                p--;
            else
                p++;
            if (p < 0)
                flag = false;
            g[l][r] = flag;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << f[i][j] << " " << g[i][j] << " " << even(j - i) << endl;
            if (f[i][j] && g[i][j] && even(j - i))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}