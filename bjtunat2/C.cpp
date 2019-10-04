#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1000100];
priority_queue<ll, vector<ll>, greater<ll>> Q;
void solve() {
    ios::sync_with_stdio(false);
    cin >> n;
    bool flag = 0;
    cin >> a[1];
    int k = a[1], x;
    while (~k & 1)
        k >>= 1;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        x = a[i];
        while (~x & 1)
            x >>= 1;
        if (k != x) {
            flag = 1;
        }
    }
    if (flag) {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        Q.push(a[i]);
    }
    int ans = 0;
    for (ll u, v; Q.size() > 1;) {
        u = Q.top();
        Q.pop();
        v = Q.top();
        // cerr << u << " " << v << endl;
        Q.pop();
        if (u != v) {
            ++ans;
            Q.push(u * 2);
            Q.push(v);
        } else {
            Q.push(u * 2);
        }
    }

    cout << ans << endl;
}
int main() {
    solve();

    return 0;
}