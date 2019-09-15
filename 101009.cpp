#include <bits/stdc++.h>

using namespace std;

bool f[2001][2001];
int dx[] = {1, -1};
int dy[] = {1, -1};

void check(int x, int y) {}

void maintain(int x, int y) {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
        }
    }
}

void knock(int x, int y) {
    f[x][y] = 0;
    maintain(x, y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, m, q, x, y;
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                f[i][j] = 1;
            }
        }
        while (q-- > 0) {
            scanf("%d %d", &x, &y);
        }
    }
    return 0;
}