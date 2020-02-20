#include <bits/stdc++.h>

using namespace std;

vector<int> vis(1000010);
int a[200050];
int dp[200050];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k, d;
        cin >> n >> k >> d;
        vis.assign(k + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int minn = 100000000;
        deque<int> q;
        int cnt = 0;
        for (int i = 1; i <= d; i++) {
            q.push_front(a[i]);
            if (vis[a[i]] == 0) {
                cnt++;
            }
            vis[a[i]]++;
        }
        dp[1] = cnt;
        minn = dp[1];
        for (int i = 2; i <= n - d + 1; i++) {
            dp[i] = dp[i - 1];
            int last = q.back();
            // cout << "back=" << last;
            q.pop_back();
            vis[last]--;
            if (vis[last] == 0) {
                dp[i]--;
            }
            int first = a[i + d - 1];
            // cout << i << " " << i + d - 1 << endl;
            q.push_front(first);
            // cout << ",first=" << first << endl;
            if (vis[first] == 0) {
                dp[i]++;
            }
            vis[first]++;
            minn = min(minn, dp[i]);
            // minn=min(dp[i-1],dp[i])
        }
        cout << minn << endl;
    }
    return 0;
}