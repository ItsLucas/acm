#include <bits/stdc++.h>
using namespace std;
int T;
int m;
long long k;
long long y;
long long ans;
int f[204], p[1004];
int a[204], b[204], c[1004];
typedef long long ll;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
long long judge(long long x) {

    if (x == 0)
        return 0;
    if (m == 1)
        return x + 1;
    if (x == 1)
        return x + m;
    int v = m;
    a[0] = b[0] = c[0] = 0;
    memset(p, 0, sizeof(p));
    c[++c[0]] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (!f[i]) {
            if (x % i == 0) {
                b[++b[0]] = i;
            } else
                c[++c[0]] = i;
        } else if (!p[i])
            c[++c[0]] = i;
        for (int j = 1; j <= b[0]; j++) {
            if (i * b[j] > 1000)
                break;
            p[b[j] * i] = 1;
            if (i % b[j] == 0)
                break;
        }
    }
    sort(c + 1, c + c[0] + 1);
    return x + c[v];
}
void gety(long long k) {
    long long l = k - m * 60;
    long long r = k + m * 60;
    long long n;
    bool flag = false;
    for (n = max(1LL, l); n <= r; n++) {
        // printf("%lld %d %lld\n", n, m, judge(n));
        if (((judge(n) - n) ^ n) == k) {
            flag = true;
            break;
        }
    }
    if (!flag)
        ans = -1;
    else
        ans = n;
    return;
}
int main() {
    scanf("%d", &T);

    for (int i = 2; i <= 200; i++) {
        if (!f[i])
            a[++a[0]] = i;
        for (int j = 1; j <= a[0]; j++) {
            f[a[j] * i] = 1;
            if (i * a[j] > 200)
                break;
            if (i % a[j] == 0)
                break;
        }
    }
    //    printf("qwq");
    for (int i = 1; i <= T; i++) {
        scanf("%lld%d", &k, &m);
        ans = -1;
        gety(k);
        printf("%lld\n", ans);
    }
}