#include <bits/stdc++.h>

using namespace std;

struct baby ///小步算法预存的结构体定义
{
    long long b, j;
    bool operator<(const baby &other) const {
        if (b == other.b)
            return j < other.j;
        return b < other.b;
    }
} babyv[100005];
long long extended_euclid(long long a, long long b, long long &x,
                          long long &y) {
    long long d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = extended_euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
long long Inv(long long a, long long n) {
    long long d, x, y;
    d = extended_euclid(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1; // no solution
}
long long gcd(long long x, long long y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
///快速幂，x^y%mod
long long q_pow(long long x, long long y, long long mod) {
    long long ans = 1;
    while (y > 0) {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
///小步预存的个数为m的结构体里面查找num
long long find(long long num, long long m) {
    long long l = 0, r = m - 1, ans = -1;
    while (r >= l) {
        long long mid = (r + l) / 2;
        if (babyv[mid].b >= num) {
            if (babyv[mid].b == num)
                ans = babyv[mid].j;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}
/// A^x=B(modC)求解x，gcd(A,C)不一定等于1，无解返回-1
long long ex_babystep_giantstep(long long A, long long B, long long C) {
    for (long long i = 0; i <= 100; i++) ///先在小于100的数里面测试
        if (q_pow(A, i, C) == B % C)
            return i;
    ///消因子， 将A^x=B%C化为d*A^(x – n)=B%C
    long long g, n = 0, d = 1;
    while ((g = gcd(A, C)) != 1) {
        if (B % g)
            return -1; ///无解
        n++;
        B /= g;
        C /= g;
        d = (d * A / g) % C;
    }
    ///无扩展小步大步操作
    long long m = ceil(sqrt(C)), ans = 1;
    for (long long j = 0; j < m; j++) ///预存操作
    {
        babyv[j].b = ans;
        babyv[j].j = j;
        ans = (ans * A) % C; ///递推
    }
    ans = 1;
    sort(babyv, babyv + m);                ///预存排序
    long long Bm = q_pow(Inv(A, C), m, C); ///算出A^(-m)%C的值
    for (long long i = 0; i < m; i++) {
        long long j = find(Inv(d, C) * B % C * ans % C, m); ///二分查找
        if (j != -1)
            return i * m + j + n; ///找到返回答案
        ans = (ans * Bm) % C;     ///继续递推
    }
    return -1; ///找不到答案
}
int main() {
    long long X, Z, K;
    while (~scanf("%lld%lld%lld", &X, &Z, &K)) {
        if (X == 0 && Z == 0 && K == 0)
            break;
        long long ans = ex_babystep_giantstep(X, K, Z);
        if (ans == -1)
            puts("No Solution");
        else
            printf("%lld\n", ans);
    }
}
