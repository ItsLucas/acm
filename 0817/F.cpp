#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 100010;
int col[maxn], le[maxn], ri[maxn];

set<pair<int, int>> ti;
int main() {
    int t;
    int x, y, z;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, m;
        scanf("%d %d", &n, &m);
        ti.clear();
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            col[i] = y;
            le[i] = x - z;
            ri[i] = x + z;
            ti.insert(make_pair(i, col[i]));
        }
    }
}