#include <bits/stdc++.h>
const int maxn = 1 << 19, mod = 1e8 + 7;
typedef long long ll;
using namespace std;
class Scanner {
#ifdef qdd
    static constexpr int BUF_SIZE = 1;
#else
    static constexpr int BUF_SIZE = 1048576; // 1MB
#endif

    char buf[BUF_SIZE], *p1 = buf, *p2 = buf;

    char nc() {
        if (p1 == p2) {
            p1 = buf;
            p2 = buf + fread(buf, 1, BUF_SIZE, stdin);
            // assert(p1 != p2);
        }
        return *p1++;
    }

  public:
    int nextInt() {
        int x = 0, sgn = 1;
        char c = nc();
        for (; c < '0' || c > '9'; c = nc())
            if (c == '-')
                sgn = -1;
        for (; c >= '0' && c <= '9'; c = nc())
            x = x * 10 + (c - '0');
        return sgn * x;
    }

    double nextDouble() {
        double x = 0, base = 0.1;
        int sgn = 1;
        char c = nc();
        for (; c < '0' || c > '9'; c = nc())
            if (c == '-')
                sgn = -1;
        for (; c >= '0' && c <= '9'; c = nc())
            x = x * 10 + (c - '0');
        for (; c < '0' || c > '9'; c = nc())
            if (c != '.')
                return sgn * x;
        for (; c >= '0' && c <= '9'; c = nc())
            x += base * (c - '0'), base *= 0.1;
        return sgn * x;
    }
} in;
int n, m;
int l[maxn], r[maxn];
int f(int a, int b) {
    int i;
    for (i = m - 1; ~i && (a & (1 << i)) == (b & (1 << i)); --i)
        ;
    return m - i - 1;
}
int add(int a, int b) {
    int ret = b + a;
    if (ret >= mod)
        ret -= mod;
    return ret;
}
int dec(int a, int b) {
    int ret = a - b;
    if (ret < 0)
        ret += mod;
    return ret;
}
int dp[maxn];
void solve() {
    n = in.nextInt();
    m = in.nextInt();
    for (int i = 0; i < n; ++i) {
        l[i] = in.nextInt();
        r[i] = in.nextInt();
    }
    for (int i = l[0]; i <= r[0]; ++i)
        dp[i] = i;
    for (int i = 1; i < n; ++i) {
        int sum = 0;
        for (int j = r[i], up = l[i - 1], down = l[i - 1]; j >= l[i]; --j) {
            for (; up <= r[i - 1] && f(up, l[i]) <= f(j, l[i]); ++up)
                sum = add(sum, dp[up]);
            for (; down <= up && f(down, l[i] - 1) < f(j, l[i] - 1); ++down)
                sum = dec(sum, dp[down]);
            dp[j] = 1ll * sum * j % mod;
        }
    }
    int ans = 0;
    for (int i = l[n - 1]; i <= r[n - 1]; ++i)
        ans = add(ans, dp[i]);
    printf("%d\n", ans);
}
int main() {

    int T;
    T = in.nextInt();
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}