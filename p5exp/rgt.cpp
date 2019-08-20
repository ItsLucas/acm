
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
void fre() {
    freopen("c://test//input.in", "r", stdin);
    freopen("c://test//output.out", "w", stdout);
}
#define MS(x, y) memset(x, y, sizeof(x))
#define MC(x, y) memcpy(x, y, sizeof(x))
#define MP(x, y) make_pair(x, y)
#define ls o << 1
#define rs o << 1 | 1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2> inline void gmax(T1 &a, T2 b) {
    if (b > a)
        a = b;
}
template <class T1, class T2> inline void gmin(T1 &a, T2 b) {
    if (b < a)
        a = b;
}
const int N = 900, M = 2e5 + 2, Z = 1e9 + 7, ms63 = 1061109567;
int n, m;
int f[2][M]; // f[][i]表示还剩下i个红色方块的方案数
void add(int &x, int y) {
    x += y;
    if (x >= Z)
        x -= Z;
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        //(top+1)top<=2(n+m)
        // top+0.<=sqrt(2(n+m))
        int top = sqrt(n + m << 1);
        while ((1 + top) * top / 2 > (n + m))
            --top;
        int sum = 0;
        int now = 0;
        int nxt = 1;
        MS(f[now], 0);
        f[0][n] = 1;
        for (int i = 1; i <= top; ++i) {
            MS(f[nxt], 0);
            for (int red = 0; red <= n; ++red) //枚举之前剩下的红色的个数
            {
                int green =
                    m + n - sum -
                    red; //其实可以直接在for循环中使得red<+m+n-sum，或者加很多剪枝的限制条件来加速
                if (green < 0)
                    break;
                if (red >= i)
                    add(f[nxt][red - i], f[now][red]);
                if (green >= i)
                    add(f[nxt][red], f[now][red]);
            }
            sum += i;
            now ^= 1;
            nxt ^= 1;
        }
        int ans = 0;
        for (int red = 0; red <= n; ++red)
            add(ans, f[now][red]);
        printf("%d\n", ans);
    }
    return 0;
}
