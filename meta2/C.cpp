#include <bits/stdc++.h>
int n, a, b, c, d, ans, x;
using namespace std;
int main() {
    scanf("%d", &n);
    a = 1, b = 2, c = 3;
    for (int i = 1; i <= n - 2; i++) {
        cout << "?"
             << " " << a << " " << b << " " << c << endl;
        ans = b;
        cin >> x;
        if (x == 1)
            b = c, c++, ans = b;
        else
            c++;
    }
    cout << "! " << ans;
    return 0;
}