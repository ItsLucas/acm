#include <bits/stdc++.h>

using namespace std;

#define N 30
int i, j, n, m, l, o, p, ans, a[30], T, tot, now;
__int128 f[N][N][N], k;
inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main() {
    //	freopen("F.in","r",stdin);
    for (i = 1; i <= 26; i++)
        for (j = 1; j <= 26; j++)
            f[i][1][j] = 1;
    for (l = 2; l <= 26; l++)
        for (i = 1; i <= 26; i++)
            for (j = 1; j <= 26; j++)
                for (o = 1; o <= std::max(i, j) + 1; o++)
                    f[i][l][j] += f[o][l - 1][std::max(i, j)];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        k = read();
        p++;
        if (n == 1) {
            printf("Case #%d: A\n", p);
            continue;
        }
        o = n - 1;
        now = 1;
        tot = 1;
        a[tot] = 1;
        while (k && tot < n) {
            __int128 sum = 0, num = 0;
            int x = 0;
            for (i = 1; i <= now + 1; i++) {
                num = sum;
                sum += f[i][o][now];
                if (sum >= k) {
                    x = i;
                    break;
                }
            }
            a[++tot] = x;
            k -= num;
            now = std::max(now, x);
            o--;
        }
        printf("Case #%d: ", p);
        for (i = 1; i <= n; i++)
            printf("%c", a[i] + 64);
        printf("\n");
    }
}