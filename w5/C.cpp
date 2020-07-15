#include <bits/stdc++.h>

using namespace std;

set<int> s;
int n, l, x, y;
bool lookup(int d) { return s.find(d) != s.end(); }

bool parse(int pos) {
    if (pos >= 0 && pos <= l) {
        // s.insert(pos);
        if (lookup(pos + y) || lookup(pos - y) || lookup(y)) {
            cout << 1 << endl;
            cout << pos << endl;
            return true;
        } else {
            // s.erase(pos);
            return false;
        }
    } else
        return false;
}
bool parse2(int pos) {
    if (pos >= 0 && pos <= l) {
        // s.insert(pos);
        if (lookup(pos + x) || lookup(pos - x) || lookup(x)) {
            cout << 1 << endl;
            cout << pos << endl;
            return true;
        } else {
            // s.erase(pos);
            return false;
        }
    } else
        return false;
}
int main() {
    cin >> n >> l >> x >> y;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }
    bool hx = false;
    bool hy = false;
    for (auto r : s) {
        if (lookup(r + x))
            hx = true;
        if (lookup(r + y))
            hy = true;
    }
    if (hx && hy) {
        cout << 0 << endl;
        return 0;
    }
    if (hx && !hy) {
        cout << 1 << endl;
        cout << y << endl;
        return 0;
    }
    if (!hx && hy) {
        cout << 1 << endl;
        cout << x << endl;
        return 0;
    }
    // r-x
    for (auto r : s) {
        if (parse(r - x) || parse(r + x) || parse2(r - y) || parse2(r + y)) {
            return 0;
        }
    }
    if ((!lookup(x)) && (!lookup(y))) {
        cout << 2 << endl;
        cout << x << " " << y << endl;
        return 0;
    }
    return 0;
}