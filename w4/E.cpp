#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

vector<int> G[2][maxn];
bool vis[2][maxn];
int cnt = 0;

void dfs(int u, int seq) {
    vis[seq][u] = 1;
    cnt++;
    for (auto v : G[seq][u]) {
        if (vis[seq][v])
            continue;
        dfs(v, seq);
    }
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        vis[0][i] = vis[1][i] = 0;
        G[0][i].clear();
        G[1][i].clear();
    }
}

inline void add(int seq, int u, int v) { G[seq][u].push_back(v); }

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        init(n);
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            add(0, x, y);
            add(1, y, x);
        }
        bool flag = false;
        for (int seq = 0; seq <= 1; seq++) {
            cnt = 0;
            dfs(1, seq);
            if (cnt < n) {
                cout << "Yes" << endl;
                flag = true;
                if (!seq) {
                    cout << cnt << " " << n - cnt << endl;
                } else {
                    cout << n - cnt << " " << cnt << endl;
                }
                for (int i = 1; i <= n; i++) {
                    if (vis[seq][i] == !seq)
                        cout << i << " ";
                }
                cout << endl;
                for (int i = 1; i <= n; i++) {
                    if (vis[seq][i] == seq)
                        cout << i << " ";
                }
                cout << endl;
                break;
            }
        }
        if (!flag)
            cout << "No" << endl;
        continue;
    }
    return 0;
}
