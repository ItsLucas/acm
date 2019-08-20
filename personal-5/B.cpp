#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int c = 1, d = 1;
    for (int a = 7; a < n; a *= 7) {
        c++;
    }
    for (int b = 7; b < m; b *= 7) {
        d++;
    }
    int ans = 0;
    if (c + d <= 7) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> v(7, 0);
                for (int a = i, k = 0; k < c; a /= 7, k++) {
                    v[a % 7] += 1;
                }
                for (int b = j, k = 0; k < d; b /= 7, k++) {
                    v[b % 7] += 1;
                }
                int maxx = 0;
                for (int i : v) {
                    maxx = max(i, maxx);
                }
                if (maxx <= 1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}