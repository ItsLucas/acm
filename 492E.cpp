#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1000010;

struct node {
    int k, x, y;
    node(int k = 0, int x = 0, int y = 0) : k(k), x(x), y(y){};
};

node p[maxn];

int xk[maxn], cnt[maxn];

int main() {
    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;
    p[0] = node(0, 0, 0);
    xk[0] = 0;
    for (int i = 1; i < n; i++) {
        p[i] = node(i, (p[i - 1].x + dx) % n, (p[i - 1].y + dy) % n);
        xk[p[i].x] = i;
    }
    int x, y, k, y0, yk;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        k = xk[x];
        yk = p[k].y;
        y0 = (y - yk + n) % n;
        cnt[y0]++;
    }
    int maxx = cnt[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (maxx < cnt[i]) {
            maxx = cnt[i], pos = i;
        }
    }
    cout << 0 << " " << pos << endl;
    return 0;
}
