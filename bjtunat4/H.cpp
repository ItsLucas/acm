#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
map<int, int> mp;
int n, m;
const int maxn = 10010;
ll ans[maxn];
int a[100], p[40], tp;
void dfs(int x, int ls, int y) {
    if (x == n) {
        a[x] = y;
        ll z = 1;
        // for(int i=1;i<=n;++i)p[i]=2;
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n; ++i)
            for (int j = 2; j <= a[i]; ++j)
                ++p[j];
        for (int i = 2, t; i < m; ++i) {
            t = i;
            for (int j = t; j; --j)
                while (t % j == 0 && p[j]) {
                    t /= j;
                    --p[j];
                }
            // cerr<<z<<endl;
            z = z * t;
        }
        ans[++tp] = z;
        return;
    }
    for (int i = ls; i <= y; ++i) {
        a[x] = i;
        dfs(x + 1, i, y - i);
    }
}
void solve() {
    cin >> n >> m;
    dfs(1, 0, m - 1);
    // cerr<<tp<<endl;
    sort(ans + 1, ans + tp + 1);
    // cerr<<tp<<endl;
    tp = unique(ans + 1, ans + tp + 1) - ans - 1;
    for (int i = 1; i <= tp; ++i)
        printf("%llu\n", ans[i]); // cout<<ans[i]<<endl;//printf("%d\n",ans[i]);
}
int main() {
    solve();

    return 0;
}