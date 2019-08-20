#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 3001;

int a[maxn], b[maxn];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int left = 0, ans = 0;
    for (int i = 1; i <= maxn; i++) {
        int cd = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] == i)
                cd += b[j];
        }
        if (cd + left <= v) {
            ans += cd + left;
            left = 0;
        } else {
            ans += v;
            int rv = v - left;
            if (rv < 0)
                rv = 0;
            left = cd - rv;
        }
    }
    cout << ans << endl;
    return 0;
}