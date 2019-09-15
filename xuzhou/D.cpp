#include <bits/stdc++.h>

char T[100010], S[100010];

void getz(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool kmp(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    getz(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            return true;
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

int main() {
    scanf("%s", T);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%s", S);
        int lent = strlen(T);
        int lens = strlen(S);
        if (lent > lens) {
            if (kmp(S, T)) {
                printf("my child!\n");
                continue;
            } else {
                printf("oh, child!\n");
                continue;
            }
        } else if (lent < lens) {
            if (kmp(T, S)) {
                printf("my teacher!\n");
                continue;
            } else {
                printf("senior!\n");
                continue;
            }
        } else {
            if (kmp(T, S)) {
                printf("jntm!\n");
                continue;
            } else {
                printf("friend!\n");
                continue;
            }
        }
    }
    return 0;
}
