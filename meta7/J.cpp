#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;

char a[maxn];
int n;
bool np[maxn];

vector<int> V[maxn], Q[maxn];

void Seive() {
    for (int i = 2; i < maxn; ++i) {
        if (np[i])
            continue;
        if (Q[i].size() != 0)
            for (auto v : Q[i])
                V[i].push_back(v);
        for (int j = i + i; j < maxn; j += i) {
            np[j] = 1;
            if (Q[j].size() != 0)
                for (auto v : Q[j])
                    V[i].push_back(v);
        }
    }
    for (int i = 1; i < maxn; ++i) {
        sort(V[i].begin(), V[i].end());
    }
}
void solve() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        Q[x].push_back(i);
    }
    Seive();
    long long ans = 0;
    for (int i = 2, ls; i < maxn; ++i) {
        if (!np[i]) {
            ls = 0;
            for (auto v : V[i]) {
                ans += 1ll * (v - ls) * (n - v + 1);
                ls = v;
            }
        }
    }
    printf("%lld\n", ans);
}
int main() {
    solve();

    return 0;
}