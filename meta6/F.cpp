#include <bits/stdc++.h>
using namespace std;
const int maxn = 4100, maxm = 1010;
char c[maxn][maxn * 2];
vector<int> G[maxm * maxm];

int n, m;
void addlink(int u, int v) {
    // cerr << u << " " << v << endl;
    G[u].push_back(v);
    G[v].push_back(u);
}
bool vis[maxm * maxm];
int nod(int i, int j) { return i * m + j; }
int bfs(int s, int t) {
    for (int i = 0; i < n * m; ++i)
        vis[i] = 0;
    queue<pair<int, int>> Q;
    while (!Q.empty())
        Q.pop();
    vis[s] = 1;
    Q.push(make_pair(s, 1));
    pair<int, int> tmp;
    for (int u, d; !Q.empty();) {
        tmp = Q.front();
        Q.pop();
        u = tmp.first;
        d = tmp.second;
        // cerr << u << endl;
        if (u == t) {
            return d;
        }
        for (auto v : G[u])
            if (!vis[v]) {
                vis[v] = 1;
                Q.push(make_pair(v, d + 1));
            }
    }
    return -1;
}
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3 + 4 * n; ++i) {
        scanf("%*[\n]%[^\n]", c[i]);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            G[nod(i, j)].clear();
    for (int i = 0; i < m; ++i)
        for (int j = 1; j < n; ++j) {
            if ((i & 1) && c[2 + 4 * j][3 + 6 * i] == 32)
                addlink(nod(j, i), nod(j - 1, i));
            if ((~i & 1) && c[4 * j][3 + 6 * i] == 32)
                addlink(nod(j, i), nod(j - 1, i));
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if ((~j & 1)) {
                if (c[1 + 4 * i][1 + 6 * j] == 32)
                    addlink(nod(i, j), nod(i - 1, j - 1));
                if (c[3 + 4 * i][1 + 6 * j] == 32)
                    addlink(nod(i, j), nod(i, j - 1));
            } else {
                if (c[3 + 4 * i][1 + 6 * j] == 32) {
                    addlink(nod(i, j), nod(i, j - 1));
                }
                if (c[5 + 4 * i][1 + 6 * j] == 32) {
                    addlink(nod(i, j), nod(i + 1, j - 1));
                }
            }
        }
    int s = -1, t = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ((~j & 1)) {
                if (c[2 + 4 * i][4 + 6 * j] == 'S')
                    s = nod(i, j);
                if (c[2 + 4 * i][4 + 6 * j] == 'T')
                    t = nod(i, j);
            } else {
                if (c[4 + 4 * i][4 + 6 * j] == 'S')
                    s = nod(i, j);
                if (c[4 + 4 * i][4 + 6 * j] == 'T')
                    t = nod(i, j);
            }
    // cerr << s << " " << t << endl;
    printf("%d\n", bfs(s, t));
}
int main() {
    // freopen("F.in", "r", stdin);
    int T;
    for (scanf("%d", &T); T--;)
        solve();
    // fclose(stdin);
    return 0;
}
/*
1
3 4
  +---+       +---+
 /     \     /     \
+       +---+       +---+
 \           \     /     \
  +   +   S   +---+   T   +
 /     \     /           /
+       +---+       +   +
 \           \     /     \
  +---+       +---+       +
 /                       /
+       +---+       +   +
 \                 /     \
  +---+       +---+       +
       \     /     \     /
        +---+       +---+

*/