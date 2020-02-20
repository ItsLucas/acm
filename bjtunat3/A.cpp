#include <bits/stdc++.h>
int a, b, xxx[3], yyy[3], i, j, k, l, ans;
const int maxn = 1e5;
void get(int x, int id) {
    if (x == 1) {
        xxx[id] = 1;
        yyy[id] = 1;
        return;
    }
    int xx, yy, p;
    for (int i = 1, j = 1; i <= maxn; i += 2, j++)
        if (1ll * i * i >= x) {
            xx = j;
            yy = 2 - j;
            l = i;
            p = i * i;
            break;
        }
    if (p - (l - 1) > x) {
        xx -= (l - 1);
        p -= (l - 1);
        if (p - (l - 1) > x) {
            yy += (l - 1);
            p -= (l - 1);
            if (p - (l - 1) > x) {
                xx += (l - 1);
                p -= (l - 1);
                yy -= (p - x);
            } else
                xx += (p - x);
        } else
            yy += (p - x);
    } else
        xx -= (p - x);
    xxx[id] = xx;
    yyy[id] = yy;
}
int main() {
    scanf("%d%d", &a, &b);
    get(a, 1);
    get(b, 2);
    ans = std::abs(xxx[1] - xxx[2]) + std::abs(yyy[1] - yyy[2]);
    printf("%d", ans);
}