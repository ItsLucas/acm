#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, r, t;
    cin >> d >> r >> t;
    int canr = 0;
    int cant = 0;
    int canto = 0;
    for (int i = 1; i <= 2333; i++) {
        if (i >= 4)
            canr += i;
        if (i - d >= 3)
            cant += i - d;
        if (canr + cant == r + t)
            break;
    }
    cout << r - canr << endl;
    return 0;
}