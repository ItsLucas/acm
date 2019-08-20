#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn (1 << 18) + 5
#define int long long

int n, m;

int s[21];

int f[maxn][105];

char ch[20];

bool vis[20];

signed main() {
    scanf("%s%lld", &ch, &m);

    int n = strlen(ch);

    f[0][0] = 1;

    int e = (1 << n);
    for (register int i = 0; i < e; i++) {
        for (register int j = 0; j < m; j++) {
            memset(vis, 0, sizeof vis);
            for (register int k = 0; k < n; k++) {
                int x = ch[k] - '0';
                if (i & (1 << k))
                    continue;
                if (i == 0 && x == 0)
                    continue;
                if (vis[x])
                    continue;
                vis[x] = 1;
                f[i | (1 << k)][(j * 10 + x) % m] += f[i][j];
            }
        }
    }

    cout << f[e - 1][0];
    return 0;
}