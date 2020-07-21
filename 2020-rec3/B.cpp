#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    char ch;
    char lastch;
    cin >> n;
    int u = 0;
    int r = 0;
    cin >> ch;
    ch == 'U' ? u++ : r++;
    lastch = ch;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        cin >> ch;
        if (ch == lastch && u == r) {
            cnt++;
        }
        lastch = ch;
        ch == 'U' ? u++ : r++;
    }
    cout << cnt << endl;
    return 0;
}