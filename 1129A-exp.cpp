#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int n, m;
int task[20010], MIN[20010];

int dist(int x, int y) { return y >= x ? y - x : y - x + n; }

int main() {
    task[0] = 20000;
    cin >> n >> m;
    memset(MIN, 0x3f, sizeof(MIN));
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        task[u]++;
        if (v > u)
            MIN[u] = min(MIN[u], v - u);
        else
            MIN[u] = min(MIN[u], v - u + n);
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (task[j] > 0)
                ans = max(ans, dist(i, j) + n * (task[j] - 1) + MIN[j]);
        }
        cout << ans << ' ';
    }
    return 0;
}
