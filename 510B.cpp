#include <bits/stdc++.h>

using namespace std;

int n, m;
char b[51][51];
bool vis[51][51];
bool flag = false;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int fx, int fy, char c) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (b[x][y] != c)
        return;
    if (vis[x][y]) {
        flag = true;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx == fx && ny == fy)
            continue;
        dfs(nx, ny, x, y, c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j, -1, -1, b[i][j]);
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}