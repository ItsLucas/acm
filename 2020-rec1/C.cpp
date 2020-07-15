#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main() {
    int k, n;
    cin >> k >> n;
    int maxx = 0;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i] - a[i - 1]);
    }
    maxx = max(maxx, k + a[1] - a[n]);
    cout << k - maxx << endl;
    return 0;
}