#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool isprime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int f(ll x) {
    if (x < 10)
        return dig[x];
    if (((x / 10) % 10) % 2 == 0)
        return (6 * f(x / 5) * dig[x % 10]) % 10;
    else
        return (4 * f(x / 5) * dig[x % 10]) % 10;
}

int main() {
    ll t;
    scanf("%lld", &t);
    while (t-- > 0) {
        ll p;
        int h;
        scanf("%lld %d", &p, &h);
        ll q;
        for (q = p - 1; q > p - 2001; q--) {
            if (isprime(q))
                break;
        }
        int dmg = f(q) * 50;
        if (dmg >= h) {
            printf("Pika\n");
        } else {
            printf("1551\n");
        }
    }

    return 0;
}