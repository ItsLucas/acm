#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
int n, m;
char s[2010][2010];
int deg[2010][2010];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct node {
    int a, b;
    node(int a = 0, int b = 0) : a(a), b(b){};
};

queue<node> Q;

int count(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == '.') {
            cnt++;
        }
    }
    return cnt;
}

void update(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == '.') {
            deg[xx][yy] = count(xx, yy);
            if (deg[xx][yy] == 1) {
                Q.push(node(xx, yy));
            }
        }
    }
}

void bfs() {
    memset(deg, 0, sizeof(deg));
    while (!Q.empty()) {
        Q.pop();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                continue;
            }
            deg[i][j] = count(i, j);
            if (deg[i][j] == 1) {
                Q.push(node(i, j));
            }
        }
    }
    int x, y;
    while (!Q.empty()) {
        node no = Q.front();
        Q.pop();
        x = no.a;
        y = no.b;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] == '.') {
                switch (i) {
                case 0:
                    s[x][y] = '<', s[xx][yy] = '>';
                    break;
                case 1:
                    s[xx][yy] = '<', s[x][y] = '>';
                    break;
                case 2:
                    s[x][y] = '^', s[xx][yy] = 'v';
                    break;
                case 3:
                    s[xx][yy] = '^', s[x][y] = 'v';
                    break;
                default:
                    break;
                }
                update(x, y);
                update(xx, yy);
                break;
            }
        }
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.')
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    bfs();
    if (check()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << s[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "Not unique" << endl;
    }
    return 0;
}