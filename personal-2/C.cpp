#include <bits/stdc++.h>
#define nop (void)0
using namespace std;

static constexpr int maxn = 1005;

char s[maxn];

inline int toi(char x) { return x - 'a'; }

char get(int t, int p) {
    for (int i = s[t] + 1; toi(i) + 1 <= p; i++) {
        if (s[t - 1] != i && s[t - 2] != i) {
            return (char)i;
        }
    }
    return 0;
}

int main() {
    int n, p, i;
    cin >> n >> p;
    scanf("%s", s);
    char t;
    i = n - 1;
    while (i >= 0) {
        t = get(i, p);
        if (t != 0) {
            s[i] = t;
            break;
        }
        i--;
    }
    if (i == -1) {
        cout << "NO" << endl;
        return 0;
    }
    i++;
    while (i < n) {
        s[i] = 'a' - 1;
        t = get(i, p);
        if (t != 0) {
            s[i] = t;
        }
        i++;
    }
    printf("%s\n", s);
    return 0;
}