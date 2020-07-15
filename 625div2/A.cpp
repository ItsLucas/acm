#include <bits/stdc++.h>

using namespace std;

int a[101], b[101];
int main() {
    int n;
    cin >> n;
    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 0) {
            sa++;
        } else if (a[i] == 0 && b[i] == 1) {
            sb++;
        }
    }
    if (sa == 0) {
        cout << -1 << endl;
    } else {
        cout << sb / sa + 1 << endl;
    }
    return 0;
}