#include <bits/stdc++.h>
using namespace std;
static constexpr int maxn = 100010;
int n, m, k, sum, a[maxn];
bool check(int x) {
    int c = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            return false;
        }
        if (t + a[i] <= x) {
            t += a[i];
        } else {
            t = a[i];
            c++;
        }
    }
    return c <= m;
}
int main() {
    cin >> n >> m >> k;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int l = 1, r = sum;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    ans--;
    cout << ans / k + 1 << endl;
    return 0;
}