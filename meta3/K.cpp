#include <bits/stdc++.h>

using namespace std;

string s;
bool check(char a, char b, char c) {
    bool f1 = false, f2 = false;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        if (s[i] == a)
            f1 = true;
        else if (s[i] == b) {
            if (f1)
                f2 = true;
        } else {
            if (f1 && f2)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> s;
    if (check('R', 'G', 'B') || check('R', 'B', 'G') || check('G', 'R', 'B') ||
        check('G', 'B', 'R') || check('B', 'G', 'R') || check('B', 'R', 'G')) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
    return 0;
}