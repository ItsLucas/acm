#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 20000070;

typedef long long ll;

int ch[maxn][2];
int sz[maxn];
int cnt = 2;

void insert(int x) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
        int p = (x >> i) & 1;
        if (!ch[u][p]) {
            ch[u][p] = cnt++;
        }
        sz[u]++;
        u = ch[u][p];
    }
    sz[u]++;
}

int query(int x, int y) {
    int u = 1;
    ll ans = 0;
    for (int i = 30; i >= 0; i--) {
        int p = (x >> i) & 1 ^ 1;
        int q = (y >> i) & 1;
        q == 0 ? ans += sz[ch[u][p]], u = ch[u][p ^ 1] : u = ch[u][p];
    }
    return ans + sz[u];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int f = 0;
    ll ans = 0;
    insert(0);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        f ^= x;
        ans += query(f, k);
        insert(f);
    }
    cout << ans << endl;
}