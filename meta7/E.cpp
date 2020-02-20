#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000010;
int n, k;
char s[maxn], t[maxn], T[maxn];
void solve() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int tg = 0;
    for (int i = 1, a, b; i + k <= n + 1; ++i) {
        tg -= T[i];
        a = s[i] - '0';
        b = t[i] - '0';
        if ((a ^ b ^ (tg & 1))) {
            ++tg;
            // cerr << i << " " << tg << endl;
            T[i + k] = 1;
        }
    }
    // tg -= T[n - k + 2];
    int flag1 = 1;
    for (int i = n - k + 2, a, b; i <= n; ++i) {
        tg -= T[i];
        a = s[i] - '0';
        b = t[i] - '0';
        // cerr << a << " " << b << " " << tg << endl;
        if ((a ^ b ^ (tg & 1))) {
            flag1 = 0;
        }
    }
    reverse(s + 1, s + n + 1);
    reverse(t + 1, t + n + 1);
    memset(T, 0, sizeof T);
    tg = 0;
    for (int i = 1, a, b; i + k <= n + 1; ++i) {
        tg -= T[i];
        a = s[i] - '0';
        b = t[i] - '0';
        if ((a ^ b ^ (tg & 1))) {
            ++tg;
            T[i + k] = 1;
        }
    }
    // tg -= T[n - k + 2];
    int flag2 = 1;
    for (int i = n - k + 2, a, b; i <= n; ++i) {
        tg -= T[i];
        a = s[i] - '0';
        b = t[i] - '0';
        // cerr << a << " " << b << " " << tg << endl;
        if ((a ^ b ^ (tg & 1))) {
            flag2 = 0;
        }
    }
    // int flag2 = 0;

    if (flag1 || flag2)
        puts("Yes");
    else
        puts("No");
}
int main() {
    solve();

    return 0;
}