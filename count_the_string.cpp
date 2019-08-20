#include <bits/stdc++.h>

char s[200010];
int z[200010];
int f[200010];

static constexpr int mod = 10007;

void getz() {
    int len = strlen(s);
    int i = 0, j = -1;
    z[0] = -1;
    while (i < len) {
        (j == -1 || s[i] == s[j]) ? z[++i] = ++j : j = z[j];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        memset(f, 0, sizeof(f));
        getz();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[z[i]] + 1;
            sum += f[i];
            sum %= mod;
        }
        printf("%d\n", sum);
    }
    return 0;
}