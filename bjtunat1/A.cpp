#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
struct Circle {
    double x, y, r;
    Circle() {}
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
};
const int maxn = 2010;
const double eps = 1e-16;
Circle a[maxn];
int fa[maxn];
int Fd(int x) {
    if (!fa[x])
        return x;
    else
        return fa[x] = Fd(fa[x]);
}
double sqr(double a) { return a * a; }
bool chk(Circle a, Circle b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y) - sqr(a.r + b.r) < eps;
}
struct Limit {
    double up, dn, lf, rt;
} lim[maxn];
int n, m, k;
void solve() {
    cin >> n >> m >> k;
    swap(n, m);
    for (int i = 1; i <= k; ++i) {
        scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
        lim[i].up = a[i].y + a[i].r;
        lim[i].dn = a[i].y - a[i].r;
        lim[i].lf = a[i].x - a[i].r;
        lim[i].rt = a[i].x + a[i].r;
    }
    for (int i = 1, u, v; i <= k; ++i) {
        for (int j = 1; j < i; ++j) {
            if (Fd(i) != Fd(j)) {
                if (chk(a[i], a[j])) {
                    // v=fa[Fd(i)] = fa[Fd(j)];
                    u = Fd(i);
                    v = Fd(j);
                    lim[u].up = max(lim[u].up, lim[v].up);
                    lim[u].dn = min(lim[u].dn, lim[v].dn);
                    lim[u].lf = min(lim[u].lf, lim[v].lf);
                    lim[u].rt = max(lim[u].rt, lim[v].rt);
                    fa[v] = u;
                }
            }
        }
    }
    bool flag = 1;
    for (int i = 1, u; i <= k; ++i) {
        u = Fd(i);
        // cerr << lim[u].up << " " << lim[u].dn << " " << lim[u].lf << " "
        //     << lim[u].rt << endl;
        if (lim[u].up - n > -eps && lim[u].dn < eps)
            flag = 0;
        else if (lim[u].rt - m > -eps && lim[u].lf < eps)
            flag = 0;
        else if (lim[u].up - n > -eps && lim[u].rt - m > -eps)
            flag = 0;
        else if (lim[u].dn < eps && lim[u].lf < eps)
            flag = 0;
    }
    if (flag)
        puts("S");
    else
        puts("N");
}
int main() {
    solve();
    return 0;
}