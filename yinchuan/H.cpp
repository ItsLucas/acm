#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct monster {
    ll hp, attack, id;
    monster(ll hp = 0, ll attack = 0, ll id = 0)
        : hp(hp), attack(attack), id(id){};
    inline bool operator<(const monster &b) const {
        return id * b.attack < attack * b.id;
    }
} mo[100010];

ll getid(ll k) {
    ll s = 1, cnt = 0;
    while (k > 0) {
        k -= s;
        cnt++, s++;
    }
    return cnt;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        int n;
        scanf("%d", &n);
        for (ll i = 1; i <= n; i++) {
            scanf("%lld %lld", &mo[i].hp, &mo[i].attack);
            mo[i].id = getid(mo[i].hp);
        }
        sort(mo + 1, mo + n + 1);
        ll ans = 0, cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += mo[i].id;
            ans += cnt * mo[i].attack;
        }
        printf("Case #%d: %lld\n", tt, ans);
    }
    return 0;
}
