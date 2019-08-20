#include <bits/stdc++.h>

using namespace std;

bool isv[256];

vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    isv['a'] = true;
    isv['e'] = true;
    isv['i'] = true;
    isv['o'] = true;
    isv['u'] = true;
    string s;
    cin >> s;
    int cv = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isv[s[i]]) {
            cv++;
        }
    }
    if (cv == 0) {
        cout << 1 << '\n';
        return 0;
    }
    if (!isv[s[0]]) {
        cout << 0 << '\n';
        return 0;
    }
    if (cv == 1) {
        cout << s.size() << '\n';
        return 0;
    }
    v.clear();
    for (int i = 0; i < s.size(); i++) {
        if (isv[s[i]]) {
            int cnt = 0;
            i++;
            while (i < s.size() && (!isv[s[i]])) {
                cnt++;
                i++;
            }
            if (i == s.size())
                break;
            v.push_back(cnt);
            i--;
        }
    }
    cout << v[v.size() / 2] + 1 << '\n';
    return 0;
}