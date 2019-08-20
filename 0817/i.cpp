#include <bits/stdc++.h>

using namespace std;

char dict[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool ccan[1010];

string s;
bool find(char c) {
    for (int i = 0; i < 11; i++) {
        if (dict[i] == c) {
            return 1;
        }
    }
    return 0;
}
int odd(int k) {
    int i = k - 1, j = k + 1, ans = 1, len = s.size();
    while (i >= 0 && j < len) {
        if (s[i] == s[j] && ccan[i]) {
            ans += 2;
        } else {
            return ans;
        }
        i--, j++;
    }
    return ans;
}
int even(int i, int j) {
    int ans = 0, len = s.size();
    while (i >= 0 && j < len) {
        if (s[i] == s[j] && ccan[i]) {
            ans += 2;
        } else {
            return ans;
        }
        i--, j++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> s;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            ccan[i] = find(s[i]);
            // cout << ccan[i] << "\n";
        }
        int ans = 0;
        if (ccan[0] || ccan[len - 1])
            ans = 1;
        for (int i = 1; i < len - 1; i++) {
            if (ccan[i]) {
                ans = max(odd(i), ans);
            }
        }
        for (int i = 1; i < len; i++) {
            ans = max(even(i - 1, i), ans);
        }

        cout << ans << "\n";
    }
    return 0;
}