#include <bits/stdc++.h>
#define N 110000
using namespace std;
char s[N];
int num[27], i, j, n, m, k, l, o, len;
bool flag;
int main() {
    scanf("%s", s);
    len = strlen(s);
    for (i = 0; i < len; i++)
        num[s[i] - 96]++;
    while (1) {
        flag = false;
        for (i = 1; i <= 25; i++) {
            int maxn = min(19, 26 - i);
            for (j = maxn; j >= 1; j--)
                if (num[i] >= (1 << j)) {
                    num[i + j] += num[i] / (1 << j);
                    num[i] %= (1 << j);
                    flag = true;
                }
        }
        if (!flag)
            break;
    }
    for (i = 26; i >= 1; i--)
        for (j = 1; j <= num[i]; j++)
            printf("%c", i + 96);
}