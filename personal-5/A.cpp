#include <bits/stdc++.h>

using namespace std;

int n;

static constexpr int maxn = 200020;
static constexpr int INF = 0x7ffffffe;

struct node {
    int v, w;
    node(int v = 0, int w = 0) : v(v), w(w){};
    inline bool operator<(const node &a) const { return w > a.w; }
};

vector<node> G[maxn];

inline void add(int u, int v, int w) { G[u].push_back(node(v, w)); }

bool vis[maxn];
int dis[maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
}

void dijkstra(int s) {
    priority_queue<node> Q;
    Q.push(node(s, 0));
    dis[s] = 0;
    while (!Q.empty()) {
        node now = Q.top();
        Q.pop();
        int v = now.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (node i : G[v]) {
            int v2 = i.v;
            int len = i.w;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                Q.push(node(v2, dis[v2]));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        if (k != i) {
            add(i, k, 1);
        }
    }
    for (int i = 2; i <= n; i++) {
        add(i, i - 1, 1);
        add(i - 1, i, 1);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    cout << endl;
    return 0;
}