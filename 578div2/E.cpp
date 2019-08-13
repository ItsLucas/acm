#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
const int INF = int(1e9);
int nxt[maxn], ex[maxn];
char f[1000010], pool[1000010];
int pos = 0;
vector<char> words[100050];

void get_next(char *str) {
    int i = 0, j, po, len = strlen(str);
    nxt[0] = len;
    while (str[i] == str[i + 1] && i + 1 < len)
        i++;
    nxt[1] = i;
    po = 1;
    for (i = 2; i < len; i++) {
        if (nxt[i - po] + i < nxt[po] + po)
            nxt[i] = nxt[i - po];
        else {
            j = nxt[po] + po - i;
            if (j < 0)
                j = 0;
            while (i + j < len && str[j] == str[j + i])
                j++;
            nxt[i] = j;
            po = i;
        }
    }
}

bool exkmp(char *s1, char *s2) {
    int i = 0, j, po, len = strlen(s1), l2 = strlen(s2);
    get_next(s2);
    while (s1[i] == s2[i] && i < l2 && i < len)
        i++;
    ex[0] = i;
    po = 0;
    if (ex[0] == l2)
        return true;
    for (i = 1; i < len; i++) {
        if (nxt[i - po] + i < ex[po] + po)
            ex[i] = nxt[i - po];
        else {
            j = ex[po] + po - i;
            if (j < 0)
                j = 0;
            while (i + j < len && j < l2 && s1[j + i] == s2[j])
                j++;
            ex[i] = j;
            po = i;
        }
        if (ex[i] == l2)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char ch = getchar();
        while (ch != ' ' && ch != EOF) {
            words[i].push_back(ch);
            ch = getchar();
        }
        if (i == 1) {
            for (char c : words[i]) {
                f[pos++] = c;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        memset(nxt, 0, sizeof(nxt));
        memset(ex, 0, sizeof(ex));
        memset(pool, 0, sizeof(pool));
        int pos2 = 0;
        for (char c : words[i]) {
            pool[pos2++] = c;
        }

        if (exkmp(f, pool)) { // 0 1 2 3 4 5 6   0 1 2 3 4
            // extend[i]表示T与S[i,n-1]的最长公共前缀
            for (int j = pos - pos2; j < pos; j++) {
                if (ex[j] == pos - j) {
                    printf("k=%d pool[k]=%c\n", j, pool[j]);
                    for (int k = j; k < pos2; k++) {
                        f[pos++] = pool[k];
                    }
                    break;
                }
            }
        } else {
            strcat(f, pool);
            pos = strlen(f) + 1;
        }
    }
    printf("%s\n", f);
    return 0;
}