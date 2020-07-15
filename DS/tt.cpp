#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
int n;
int G[maxn][maxn];
int vis[maxn];
bool dfs(int fa) {
    vis[fa] = -1;
    for (int i = 1; i <= n; i++) {
        if (G[fa][i]) {
            if (vis[i] < 0)
                return false;
            else if (!vis[i] && !dfs(i))
                return false;
        }
    }
    vis[fa] = true;
    return true;
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i)) {
                cout << "Have loop" << endl;
                return 0;
            }
        }
    }
    cout << "Don't have loop" << endl;
    return 0;
}