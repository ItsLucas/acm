#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        string s;
        cin >> s;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'z') {
                s[i] = 'b';
                cout << s << endl;
                flag = 1;
                break;
            } else if (s[i] == 'y') {
                continue;
            } else {
                cout << s << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << s << endl;
    }
    return 0;
}