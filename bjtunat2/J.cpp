#include <bits/stdc++.h>
long long a, b, x, y, ans, p;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    p = gcd(x, y);
    x /= p;
    y /= p;
    ans = std::min(a / x, b / y);
    printf("%lld", ans);
}