#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, ans, t;
set<int> s[2][2];
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = n; i; ++t, i >>= 1)
        ;
    for (int i = 1; i <= n; ++i)
        s[1][0].insert(i);
    for (int i = 0, a, st, num = 0; i < t; ++i) {
        st = i & 1;
        s[st][0].clear();
        s[st][1].clear();

        for (auto j : s[st ^ 1][num]) {
            cout << "? " << j << " " << i << endl;
            cout.flush();
            cin >> a;
            s[st][a].insert(j);
        }
        if (s[st][0].size() > s[st][1].size())
            num = 1;
        else
            num = 0;
        ans |= (num << i);
    }
    cout << "! " << ans << endl;
    cout.flush();
    // printf("%d\n", ans);
}
int main() {
    solve();

    return 0;
}