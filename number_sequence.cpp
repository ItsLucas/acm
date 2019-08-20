#include <bits/stdc++.h>

using namespace std;

int f[50];

int main() {
    int a, b, n;
    while (1) {
        cin >> a >> b >> n;
        if (a == 0 && b == 0 && n == 0)
            break;
        memset(f, 0, sizeof(f));
        f[1] = 1, f[2] = 1;
        for (int i = 3; i <= 49; i++) {
            f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
        }
        cout << f[n % 49] << endl;
    }
    return 0;
}