#include <bits/stdc++.h>
using namespace std;
static constexpr int maxn = 2e5 + 10;
struct seg {
    int l, r;
} a[maxn];
int n, h, hh, l, r, ans, tmp;
int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    l = 1, r = 1;
    while (r <= n) {
        if (r > 1) {
            hh += a[r].l - a[r - 1].r;
            while (hh >= h) {
                hh -= a[l + 1].l - a[l].r;
                tmp -= a[l].r - a[l].l;
                l++;
            }
        }
        tmp += a[r].r - a[r].l;
        r++;
        ans = max(ans, tmp);
    }
    cout << ans + h << endl;
    return 0;
}