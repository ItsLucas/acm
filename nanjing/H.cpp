#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
static constexpr int maxn = 301;
static constexpr ll inf = 1e18;

struct node {
    int v;
    ll w;
    node(int v = 0, ll w = 0) : v(v), w(w){};
};

vector<node> G[maxn];
ll dis[maxn];
bool vis[maxn];

inline void add(int u, int v, int w) { G[u].push_back(node(v, w)); }

bool spfa(int s, int n) {
    queue<int> q;
    memset(dis, inf, sizeof(dis));
    memset(vis, 1, sizeof(vis));
    dis[s] = 0; //初始化距离
    q.push(s);
    vis[s] = false;
    while (!q.empty()) {
        int x = q.front();
        q.pop();            //出队
        vis[x] = true;      //标记不在队列
        for (node i : G[x]) //遍历与x节点连通的点
        {
            printf("%d %d\n", x, i.v);
            int y = i.v;
            if (dis[y] > dis[x] + i.w) //更新
            {
                dis[y] = dis[x] + i.w;
                printf("dis[y]=%lld\n", dis[y]);
                if (vis[y]) {
                    q.push(y);
                    vis[y] = false;
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        int n, m, x, y, w;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d %lld", &x, &y, &w);
            add(x, y, w);
        }
        for (int i = 1; i <= 6; i++) {
            scanf("%d %d", &x, &y);
            spfa(y, n - 1);
            printf("%d\n", -dis[x]);
            add(x, y, -dis[x]);
        }
    }
    return 0;
}