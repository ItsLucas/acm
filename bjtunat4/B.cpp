#include <bits/stdc++.h>
using namespace std;

static constexpr int maxn = 100010;

struct Vector {
    int x, y;
};
Vector pp[maxn], vc[maxn];

inline double dc(Vector a, Vector b) {
    return 1.0 * a.x * b.y - 1.0 * a.y * b.x;
}

inline int xs(Vector a) {
    if (a.x >= 0 && a.y > 0)
        return 1;
    if (a.x < 0 && a.y >= 0)
        return 2;
    if (a.x <= 0 && a.y < 0)
        return 3;
    if (a.x > 0 && a.y <= 0)
        return 4;
}

bool operator<(const Vector &a, const Vector &b) {
    Vector p1 = a;
    Vector p2 = b;
    int l1, l2;
    l1 = xs(p1);
    l2 = xs(p2);
    return l1 == l2 ? dc(a, b) > 0 ? 1 : 0 : l1 < l2;
}

inline Vector mov(Vector x, Vector base) {
    return {x.x - base.x, x.y - base.y};
}

inline Vector mirror(Vector x) { return {-1 * x.x, -1 * x.y}; }
int sum[6];
int main() {
    int n;
    cin >> n;
    sum[5] = 0;
    for (int i = 0; i < n; i++) {
        cin >> pp[i].x >> pp[i].y;
        vc[i] = mov(pp[i], pp[0]);
        if (vc[i].x == 0 && vc[i].y == 0) {
            vc[i] = {1, 1};
            sum[5]++;
        }
        if (i == 0)
            continue;
        if (vc[i].x >= 0)
            sum[1]++;
        if (vc[i].x > 0)
            sum[2]++;
        if (vc[i].y >= 0)
            sum[3]++;
        if (vc[i].y > 0)
            sum[4]++;
    }
    sort(vc + 1, vc + n);
    int maxr = 0, minr = 23333333;
    for (int i = 1; i < n; i++) {
        if (vc[i].x <= 0 && vc[i].y >= 0) {
            Vector a = mirror(vc[i]);
            int c = lower_bound(vc + 1, vc + n, a) - vc;
            int d = upper_bound(vc + 1, vc + n, a) - vc;
            int now = i;
            if (c >= i)
                now += n - 1;
            else if (d >= i)
                now += n - 1;
            maxr = max((now - c + 1) + 1, maxr);
            minr = min((now - d + 1 - sum[5]) + 1, minr);
        } else {
            continue;
        }
    }
    minr = min(minr, sum[2] + 1);
    minr = min(minr, sum[4] + 1);
    maxr = max(maxr, sum[1] + 1);
    maxr = max(maxr, sum[3] + 1);
    cout << minr << " " << maxr << endl;
    return 0;
}