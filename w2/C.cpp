#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

typedef long long ll;

struct node {
    ll u;
    int v;
    node(ll u, int v) : u(u), v(v){};
    bool operator<(const node &a) const {
        return u < a.u || (!(a.u < u) && v < a.v);
    }
};

vector<node> G[maxn];
vector<node> es;

ll a[maxn], dep[maxn];
int sum[maxn];

inline void add(int u, int v, int w) { G[u].push_back(node(v, w)); }
inline auto get(node n) {
    return lower_bound(es.begin(), es.end(), n) - es.begin();
}

void dfs(int u) {
    sum[u]++;
    int p = get(node(dep[u] - a[u], -1)) - 1;
    if (p >= 0)
        sum[es[p].v]--;
    es.push_back(node(dep[u], u));
    for (auto v : G[u]) {
        dep[v.u] = dep[u] + v.v;
        dfs(v.u);
        sum[u] += sum[v.u];
    }
    es.pop_back();
}

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> x >> y;
        add(x, i, y);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << sum[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}