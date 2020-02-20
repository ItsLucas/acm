#include <bits/stdc++.h>

using namespace std;

int a[2001];

inline bool cmp(int a, int b) { return a > b; }
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}