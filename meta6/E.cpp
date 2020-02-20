#include <bits/stdc++.h>
using namespace std;
#define N 120
int a[N], b[N], T, t[10 * N], i, j, n, m, k, l, o, p, len1, len2, tot, x[N],
    y[N], sum;
int ans1[10 * N], ans2[10 * N];
char s[N];
bool ss(int x) {
    if (x == 2)
        return true;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
void cheng(int x) {
    int i;
    for (i = 1; i <= len2; i++)
        b[i] *= x;
    for (i = 1; i <= len2; i++)
        if (b[i] >= 10) {
            if (i < len2)
                b[i + 1] += b[i] / 10, b[i] %= 10;
            else
                while (b[len2] >= 10)
                    ++len2, b[len2] += b[len2 - 1] / 10, b[len2 - 1] %= 10;
        }
}
bool pd() {
    if (len2 > len1)
        return true;
    if (len2 < len1)
        return false;
    for (int i = len2; i >= 1; i--)
        if (b[i] > a[i])
            return true;
        else if (b[i] < a[i])
            return false;
    return false;
}
int main() {
    cin >> T;
    for (i = 2; i <= 1000; i++)
        if (ss(i))
            t[++tot] = i;
    while (T-- > 0) {
        // i = 0, j = 0, n = 0, m = 0, k = 0, l = 0, o = 0, p = 0, len1 = 0,
        len2 = 0;
        scanf("%s", s);
        if (strlen(s) == 1 && s[0] == '2') {
            puts("2/3");
            continue;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        len1 = strlen(s);
        for (i = 1; i <= len1; i++)
            a[i] = s[len1 - i] - '0';
        len2 = 1;
        b[1] = 1;
        sum = 0;
        for (i = 1; i <= tot; i++) {
            cheng(t[i]);
            if (pd())
                break;
            else
                x[++sum] = t[i], y[sum] = t[i] + 1;
        }
        for (i = 1; i <= sum; i++)
            for (j = 1; j <= sum; j++)
                if (y[j] % x[i] == 0) {
                    y[j] /= x[i], x[i] = 1;
                    break;
                }
        len1 = len2 = 1;
        memset(ans1, 0, sizeof ans1);
        memset(ans2, 0, sizeof ans2);
        ans1[1] = ans2[1] = 1;
        for (i = 1; i <= sum; i++) {
            for (j = 1; j <= len1; j++)
                ans1[j] *= x[i];
            for (j = 1; j <= len2; j++)
                ans2[j] *= y[i];
            for (j = 1; j <= len1; j++)
                if (ans1[j] >= 10) {
                    if (j < len1)
                        ans1[j + 1] += ans1[j] / 10, ans1[j] %= 10;
                    else
                        while (ans1[len1] >= 10)
                            ++len1, ans1[len1] += ans1[len1 - 1] / 10,
                                ans1[len1 - 1] %= 10;
                }
            for (j = 1; j <= len2; j++)
                if (ans2[j] >= 10) {
                    if (j < len2)
                        ans2[j + 1] += ans2[j] / 10, ans2[j] %= 10;
                    else
                        while (ans2[len2] >= 10) {
                            ++len2, ans2[len2] += ans2[len2 - 1] / 10,
                                ans2[len2 - 1] %= 10;
                        }
                }
        }
        for (i = len1; i >= 1; i--)
            printf("%d", ans1[i]);
        printf("/");
        for (i = len2; i >= 1; i--)
            printf("%d", ans2[i]);
        printf("\n");
    }
    return 0;
}