#include <bits/stdc++.h>

using namespace std;

set<int> s;
bool split_num(long x) {
    long y, n;
    y = x;
    n = 1;
    while (y > 10) {
        n *= 10;
        y = y / 10;
    }
    s.clear();
    do {
        if (s.find(x / n) != s.end()) {
            return false;
        } else {
            s.insert(x / n);
        }
        x = x % n;
        n = n / 10;
    } while (n >= 1);
    return true;
}

int main() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (split_num(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}