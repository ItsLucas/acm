#include <bits/stdc++.h>

using namespace std;

char tg[2005], tx[2005];

bool cmp() {
    bool flag = true;
    if (strlen(tx) != strlen(tg))
        return false;
    for (int i = 0; i < strlen(tg); i++) {
        if (tg[i] == tx[i])
            continue;
        else
            flag = false;
    }
    return flag;
}
int main() {
    int n;
    cin >> n;
    int pos2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", tg + pos2);
        pos2 = strlen(tg) + 1;
        tg[pos2 - 1] = ' ';
    }
    pos2 = strlen(tg) + 1;
    tg[pos2 - 2] = 0;
    int ops;
    cin >> ops;
    int cur = 0;
    bool caps = false;
    for (int i = 1; i <= ops; i++) {
        string s;
        cin >> s;
        if (s == "CapsLock") {
            caps = !caps;
        } else if (s == "Backspace") {
            if (cur == 0)
                continue;
            else {
                cur--;
                tx[cur] = 0;
            }
        } else if (s == "Space") {
            tx[cur] = ' ';
            cur++;
        } else {
            if (caps)
                tx[cur] = toupper(s[0]);
            else
                tx[cur] = s[0];
            cur++;
        }
    }
    // cout << tx << endl;
    if (cmp() == 1) {
        cout << "Correct" << endl;
    } else
        cout << "Incorrect" << endl;
    return 0;
}