#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;
int a[maxn], b[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    bool state = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] += b[i - 1] + (state ? a[i] - a[i - 1] : 0);
        state = !state;
    }
    b[n + 1] = b[n] + (state ? m - a[n] : 0);
    int ans = b[n + 1];
    a[n + 1] = m;
    for (int i = 1; i <= n; i++) {
        int tmp;
        if (i & 1)
            tmp = m - a[i] + 2 * b[i] - b[n + 1] - 1;
        else
            tmp = m - a[i + 1] + 2 * b[i + 1] - b[n + 1] - 1;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}