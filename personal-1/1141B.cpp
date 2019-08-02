#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 200050;

int a[200050];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, len = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i % n] == 1) {
            len++;
            ans = max(ans, len);
        } else {
            len = 0;
        }
    }
    cout << ans << endl;
}