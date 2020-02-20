#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> s[2010];
int a[2010], n;
void solve() {
    scanf("%d", &n);
    unordered_map<int, int> s[n + 3];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    ++s[n][a[n]];
    for (int i = n - 1; i >= 1; --i) {
        s[i] = s[i + 1];
        ++s[i][a[i]];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            ans += s[j + 1][2 * a[j] - a[i]];
        }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();

    return 0;
}