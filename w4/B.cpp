#include <bits/stdc++.h>

using namespace std;

const int P = 100019;
const int E = 19260817;

int main() {
    int n, m;
    cin >> n >> m;
    cout << P << " " << P << endl;
    cout << 1 << " " << 2 << " " << P - n + 2 << endl;
    for (int i = 1; i < n - 1; i++) {
        cout << i + 1 << " " << i + 2 << " " << 1 << endl;
    }
    int l = 1, r = 3;
    for (int i = 1; i <= m - n + 1; i++) {
        cout << l << " " << r << " " << E << endl;
        r++;
        if (r > n) {
            l++;
            r = l + 2;
        }
    }
    return 0;
}