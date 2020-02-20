#include <bits/stdc++.h>
char s[200];
int len, i, j, n, m, k;
char x;
int main() {
    scanf("%c\n", &x);
    scanf("%d\n", &k);
    if (x == 'D')
        k *= -1;
    scanf("%s", s);
    len = strlen(s);
    for (i = 0; i < len; i++) {
        int x = s[i] + k;
        if (x < 97)
            x += 26;
        else if (x > 122)
            x -= 26;
        printf("%c", x);
    }
}