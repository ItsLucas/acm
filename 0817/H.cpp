#include <bits/stdc++.h>

using namespace std;

char dict[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool find(char c) {
    for (int i = 0; i < 11; i++) {
        if (dict[i] == c) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (!find(s[i])) {
                cout << "no" << '\n';
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != s[len - i - 1]) {
                cout << "no" << '\n';
                flag = false;
                bre #include<bits / stdc++.h>

                    using namespace std;

                char dict[11] = {'A', 'H', 'I', 'M', 'O', 'T',
                                 'U', 'V', 'W', 'X', 'Y'};

                bool find(char c) {
                    for (int i = 0; i < 11; i++) {
                        if (dict[i] == c) {
                            return true;
                        }
                    }
                    return false;
                }

                int main() {
                    ios::sync_with_stdio(false);
                    cin.tie(0);
                    cout.tie(0);
                    int t;
                    cin >> t;
                    while (t-- > 0) {
                        string s;
                        cin >> s;
                        bool flag = true;
                        for (int i = 0; i < s.size(); i++) {
                            if (!find(s[i])) {
                                cout << "no" << '\n';
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) {
                            continue;
                        }
                        int len = s.size();
                        for (int i = 0; i < len; i++) {
                            if (s[i] != s[len - i - 1]) {
                                cout << "no" << '\n';
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) {
                            continue;
                        }
                        cout << "yes" << '\n';
                    }
                    return 0;
                }
                ak;
            }
        }
        if (!flag) {
            continue;
        }
        cout << "yes" << '\n';
    }
    return 0;
}