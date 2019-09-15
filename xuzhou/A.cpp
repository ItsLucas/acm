typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll tp = x;
    x = y;
    y = tp - a / b * y;
    return gcd;
}

ll excrt() {
    ll x, y, k;
    ll M = bi[1], ans = ai[1];
    for (int i = 2; i <= n; i++) {
        ll a = M, b = bi[i], c = (ai[i] - ans % b + b) % b;
        ll gcd = exgcd(a, b, x, y), bg = b / gcd;
        if (c % gcd != 0)
            return -1;

        x = mul(x, c / gcd, bg);
        ans += x * M;
        M *= bg;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
