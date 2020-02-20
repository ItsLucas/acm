#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 100050;
int a[maxn], b[maxn];

inline char toi(char s) { return s - '0'; }

int main() {
    string s;
    cin >> s;
    int n = s.size();
    a[0] = toi(s[0]);
    b[0] = 11 - toi(s[0]);
    for (int i = 1; i < n; i++) {
        a[i] = min(a[i - 1], b[i - 1]) + toi(s[i]);
        b[i] = min(a[i - 1] + 11 - toi(s[i]), b[i - 1] + 9 - toi(s[i]));
    }
    cout << min(a[n - 1], b[n - 1]) << endl;
    return 0;
}