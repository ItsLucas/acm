#include <bits/stdc++.h>

using namespace std;

char s1[10], s2;

int main() {
    while (cin >> s1) {
        if (s1[0] != 's')
            break;
        int x = 1, y = 2;
        while (true) {
            cout << "? " << x << " " << y << endl;
            fflush(stdout);
            cin >> s2;
            if (s2 == 'x')
                break;
            x = y;
            y <<= 1;
        }
        int l = x, r = y, mid;
        while (l < r - 1) {
            mid = (l + r) >> 1;
            cout << "? " << mid << " " << l << endl;
            fflush(stdout);
            cin >> s2;
            if (s2 == 'x')
                l = mid;
            else
                r = mid;
        }
        cout << "? " << r << " " << l << endl;
        cin >> s2;
        if (s2 == 'x')
            cout << "! " << l << endl;
        else
            cout << "! " << r << endl;
        fflush(stdout);
    }
}