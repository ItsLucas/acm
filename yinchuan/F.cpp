#include <bits/stdc++.h>

using namespace std;

static constexpr int INF = INT_MAX - 1;
static constexpr int maxn = 201;

int mp[maxn][maxn][maxn];
int risk[maxn], node[maxn];

inline bool cmp(int i, int j) { return risk[i] < risk[j]; }

inline void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[k][i][j] = min(mp[k - 1][i][j], mp[k - 1][i][node[k]] +
                                                       mp[k - 1][node[k]][j]);
            }
        }
    }
}

int main() {
    int n, q, t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        memset(mp, INF, sizeof(mp));
        memset(risk, 0, sizeof(risk));
        memset(node, 0, sizeof(node));
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &risk[i]);
            node[i] = i;
        }
        sort(node + 1, node + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &mp[0][i][j]);
            }
        }
        floyd(n);
        printf("Case #%d: \n", tt);
        while (q-- > 0) {
            int u, v, r, k = 0;
            scanf("%d %d %d", &u, &v, &r);
            for (int i = 1; i <= n; i++) {
                risk[node[i]] <= r ? k = i : k = k;
            }
            printf("%d\n", mp[k][u][v]);
        }
    }
    return 0;
}