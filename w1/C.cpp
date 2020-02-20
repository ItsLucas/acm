#include <bits/stdc++.h>

using namespace std;

int co[1000010];
char ori[500010];
int sum[1000010];
int ans;
int main() {
    int n, a, b, t;
    cin >> n >> a >> b >> t;
    scanf("%s", ori + 1);
    for (int i = 1; i <= n; i++) {
        if (ori[i] == 'w')
            co[i] = co[i + n] = b + 1;
        else
            co[i] = co[i + n] = 1;
    }
    for (int i = 1; i <= n + n; i++) {
        sum[i] = sum[i - 1] + co[i];
    }
    int l = 2, r = n + 1;
    while (l <= n + 1 && r <= n + n) {
        while (r - l + 1 > n ||
               sum[r] - sum[l - 1] + (r - l + min(r - n - 1, n - l + 1)) * a >
                   t)
            l++;
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << endl;
    return 0;
}