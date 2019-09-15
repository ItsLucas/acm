#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<long long, long long> pii;
const int maxn = 1e5 + 10;
long long b[maxn];
void ddo() {
    int n;
    vector<pair<pii, int>> sing;
    vector<pair<pii, int>> talk;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        sing.push_back(mp(mp(x, y), i));
        talk.push_back(mp(mp(y, x), i));
    }
    sort(sing.begin(), sing.end());
    sort(talk.begin(), talk.end());
    for (int i = 0; i <= n; i++) {
        b[i] = talk[i].first.first;
    }
    long long maxx = -1, ans = 1e18 + 5;
    long long x;
    int z;
    for (int i = sing.size() - 1; i >= 0; i--) {
        if (maxx >= sing[i].first.first) {
            ans = min(ans, maxx - sing[i].first.first);
            break;
        }
        long long temp = 1e18 + 5;
        x = sing[i].first.first;
        // cout<<"^^^"<<x<<"\n";
        z = lower_bound(b, b + n, x) - b;
        // cout<<"!!!"<<z<<"\n";
        for (int j = max(0, z - 2); j <= min(z + 1, n - 1); j++) {
            // cout<<"@@"<<j<<"\n";
            if (sing[i].second != talk[j].second) {
                temp =
                    min(temp, abs(sing[i].first.first - talk[j].first.first));
                // cout<<"$$$"<<i<<" "<<j<<" "<<sing[i].first.first<<"
                // "<<talk[j].first.first<<"\n";
            }
        }
        ans = min(ans, temp);
        // cout<<"^^^"<<ans<<"\n";
        if (ans == 0)
            break;
        maxx = max(maxx, sing[i].first.second);
    }
    printf("%lld\n", ans);
    return;
}