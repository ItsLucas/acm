#include <bits/stdc++.h>
#define nop void(0)
using namespace std;

static constexpr int maxn = 100010;

vector<int> G[maxn];
vector<int> ans;

int a[maxn], b[maxn];

inline void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(int p, int val, int k1 = 0, int k2 = 0, int h = 0) {
    (k1 && (h & 1)) ? (a[p] ^= 1) : a[p] = a[p];
    (k2 && !(h & 1)) ? (a[p] ^= 1) : a[p] = a[p];
    a[p] != b[p] ? (h & 1 ? k1 ^= 1 : k2 ^= 1, ans.push_back(p)) : (void)0;
    for (int i : G[p]) {
        if (i != val) {
            dfs(i, p, k1, k2, h + 1);
        }
    }
}

int main() {
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dfs(1, -1);
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << endl;
    }
    return 0;
}