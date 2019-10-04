#include <bits/stdc++.h>

using namespace std;

int a[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] > 1) {
            ans += (a[i] - a[i - 1] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}