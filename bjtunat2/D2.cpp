#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
static constexpr int inf = 0x3f3f3f3f;
static constexpr int maxn = 2e5 + 10;
static constexpr int maxm = 1e7 + 10;
int a[maxn], b[maxm], c[maxm];
vector<pair<int, int>> ans(maxn);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        bool k = false;
        if (c[a[i]] > 0) {
            ans[i].first = c[a[i]];
            ans[i].second = a[i] / ans[i].first;
            c[a[i]] = 0;
            k = true;
        } else {
            while (1) {
                b[a[i]]++;
                if (b[a[i]] * b[a[i]] > a[i]) {
                    flag = false;
                    break;
                }
                if (a[i] % b[a[i]] == 0) {
                    ans[i].first = b[a[i]];
                    ans[i].second = a[i] / b[a[i]];
                    if (ans[i].first != ans[i].second) {
                        c[a[i]] = a[i] / b[a[i]];
                    }
                    k = true;
                    break;
                }
            }
        }
        if (!k)
            flag = false;
        if (!flag)
            break;
    }
    if (!flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}