#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct cl {
    int id;
    ll p, t;
};

cl clp[1000001], clt[1000001];

bool cmp1(cl a, cl b) { return a.p < b.p; }

bool cmp2(cl a, cl b) { return a.t > b.t; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        ll tot = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            clp[i].id = i;
            cin >> clp[i].p >> clp[i].t;
            tot += clp[i].p;
            clt[i].id = i;
            clt[i] = clp[i];
        }
        sort(clp + 1, clp + n + 1, cmp1);
        sort(clt + 1, clt + n + 1, cmp2);
        ll pool = clt[1].t;
        int nowid = clt[1].id;
        int pos = 1;
        int next = 2;
        while (pool != 0 && tot > 0) {
            if (clp[pos].id == nowid) {
                pos++;
                continue;
            }
            while (clp[pos].p > 0 && pool != 0) {
                ll diff = min(clp[pos].p, pool);
                ans += diff;
                pool -= diff;
                tot -= diff;
                if (pool == 0) {
                    pool = clt[next].t;
                    nowid = clt[next].id;
                    next++;
                }
            }
            pool += clp[pos].t;
            clp[pos].t = 0;
            pos++;
        }
        cout << ans << endl;
    }
    return 0;
}