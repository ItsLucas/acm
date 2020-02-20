#include <bits/stdc++.h>

using namespace std;

char c[200050];

int main() {
    int pos = 1;
    string s;
    cin >> s;
    bool flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            c[pos++] = s[i];
        }

        else {
            break;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= pos - 1; i++) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}