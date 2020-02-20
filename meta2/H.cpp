#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

static constexpr int maxn = 10000010;

vector<int> prime;
bool vis[maxn];

void sieve() {
    int x = sqrt(maxn);
    for (int i = 3; i <= x; i += 2) {
        if (!vis[i]) {
            for (int j = i * i; j < maxn; j += 2 * i) {
                vis[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i < maxn; i += 2) {
        if (!vis[i])
            prime.push_back(i);
    }
}

int main() {
    sieve();
    ll n;
    cin >> n;
    ll ans = 1, rt = sqrt(n);
    for (int i = 0; i < prime.size() && prime[i] <= rt; i++) {
        int cnt = 0;
        while (n % prime[i] == 0) {
            cnt++;
            n /= prime[i];
        }
        if (cnt & 1) {
            ans *= prime[i];
        }
    }
    rt = sqrt(n);
    if (rt * rt != n)
        ans *= n;
    cout << ans << endl;
    return 0;
}