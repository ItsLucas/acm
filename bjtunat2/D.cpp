#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxm = 1e7 + 7;
bool np[maxn];
vector<int> p;
int a[maxm], b[maxm], flag[maxm], cnt[maxm], chk[maxm], tag[maxm];
void init() {
    np[1] = 0;
    p.push_back(1);
    for (int i = 2; i < maxn; ++i) {
        if (!np[i]) {
            p.push_back(i);
        }
        for (int j = 0; j < p.size() && i * p[j] < maxn; ++j) {
            np[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }
}
int c[maxn];
int A[maxn], B[maxn];
int n;
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
        b[c[i]] = c[i];
        a[c[i]] = 1;
    }
    bool ans = 1;
    for (int i = 1, x; i <= n; ++i) {
        x = c[i];
        if (tag[c[i]])
            continue;
        tag[c[i]] = 1;
        for (int j = 0; j < p.size() && p[j] * p[j] <= x; ++j) {
            if (x % p[j] == 0) {
                ++++chk[c[i]];
            }
            if (p[j] * p[j] == x)
                --chk[c[i]];
        }
    }
    // memset(flag, 0, sizeof flag);
    // cerr << chk[3] << endl;
    for (int i = 1; i <= n; ++i) {
        if (flag[c[i]] == 1) {
            flag[c[i]] = 0, A[i] = a[c[i]];
            // if(cnt[c[i]]>chk[c[i]])ans=0;
            ++cnt[c[i]];
            for (int j = 1; j < p.size() && p[j] * p[j] <= b[c[i]]; ++j) {
                if (b[c[i]] % p[j] == 0) {
                    b[c[i]] /= p[j];
                    a[c[i]] *= p[j];
                    break;
                }
            }
        } else
            flag[c[i]] = 1, A[i] = b[c[i]], ++cnt[c[i]];
        if (cnt[c[i]] > chk[c[i]])
            ans = 0;
    }
    for (int i = 1; i <= n; ++i)
        if (!A[i])
            ans = 0;
    if (ans) {
        puts("YES");
        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", A[i], c[i] / A[i]);
    } else {
        puts("NO");
    }
}
int main() {
    init();
    solve();
    return 0;
}