#include <cstdio>
#include <cstring>

using namespace std;

char s[1000010];
int z[1000010];

void getz() {
    int len = strlen(s);
    int i = 0, j = -1;
    z[0] = -1;
    while (i < len) {
        j == -1 || s[i] == s[j] ? z[++i] = ++j : j = z[j];
    }
}

int main() {
    while (scanf("%s", s)) {
        if (s[0] == '.') {
            break;
        }
        getz();
        int len = strlen(s);
        if (len % (len - z[len]) == 0) {
            printf("%d\n", len / (len - z[len]));
        } else {
            printf("1\n");
        }
    }
    return 0;
}