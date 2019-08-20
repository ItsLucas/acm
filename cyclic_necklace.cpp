#include <bits/stdc++.h>

#define NOTLE ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

char s[100010];
int nxt[100010];

inline void kmp(int len) {
    nxt[0] = -1;
    for (int i = 0; i < len; i++) {
        int j = nxt[i];
        while (j != -1 && s[j] != s[i]) {
            j = nxt[j];
        }
        nxt[i + 1] = j + 1;
    }
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s", s);
        int len = strlen(s);
        kmp(len);
        int sum = len - nxt[len];
        if (!nxt[len]) {
            printf("%d\n", len);
        } else if (!(len % sum)) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", sum - (len % sum));
        }
    }
    return 0;
}