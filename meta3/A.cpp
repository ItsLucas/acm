#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 500010;

int a[maxn], p[maxn], ans[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        p[i] = n;
    }
    int minx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            p[a[i]] = i;
        } else {
            minx = min(minx, p[-a[i]] - 1);
        }
        ans[i] = minx;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] - i + 1 << " ";
    }
    cout << endl;
    return 0;
}