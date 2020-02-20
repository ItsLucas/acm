#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b - a == 0) {
        cout << a << "00 " << b << "01" << endl;
    } else if (b - a == 1) {
        cout << a << "99 " << b << "00" << endl;
    } else if (a == 9 && b == 1) {
        cout << "99 100" << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}