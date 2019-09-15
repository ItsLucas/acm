#include <bits/stdc++.h>

using namespace std;

namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <typename T> inline void read(T &x) {
    char ch;
    while (blank(ch = nc()))
        ;
    if (IOerror)
        return;
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
}
#undef BUF_SIZE
}; // namespace fastIO

using namespace fastIO;

unordered_map<int, int> fa;
int i, j, n, m, k, l, o, p, ans;
inline int get(int x) {
    if (fa[x] == 0)
        return x;
    else
        return fa[x] = get(fa[x]);
}
int main() {
    read(n);
    read(m);
    // printf("nm%d %d\n", n, m);
    for (i = 1; i <= m; i++) {
        int x, y;
        read(x);
        read(y);
        // printf("xy%d %d\n", x, y);
        if (x == 1) {
            fa[y] = get(y + 1);
        } else {
            ans = get(y);
            printf("%d\n", ans);
        }
    }
}