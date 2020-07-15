#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map<ll, int> mp;
ll ans[200010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b + 1]--;
    }
    ll pos = 0;
    int cnt = 0;
    bool flag = false;
    for (auto i : mp) {
        if (!flag) {
            pos = i.first;
            cnt += i.second;
            flag = true;
        } else {
            ans[cnt] += i.first - pos;
            pos = i.first;
            cnt += i.second;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}