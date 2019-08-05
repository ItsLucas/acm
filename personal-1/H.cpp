#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000010;
const int INF = 0x7f7f7f7f;

struct node {
    int v;
    int c;
    node(int v = 0, int c = 0) : v(v), c(c) {}
    bool operator<(const node &r) const { return c > r.c; }
};

struct Edge {
    int v, cost;
    int next;
};

Edge edge[200000];
int tol;
int head[maxn];
bool vis[maxn];
int dist[maxn];

void dijkstra(int n, int start) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    priority_queue<node> que;
    while (!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(node(start, 0));
    node tmp;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int cost = edge[i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                que.push(node(v, dist[v]));
            }
        }
    }
}

inline void add(int u, int v, int w) {
    edge[tol].v = v;
    edge[tol].cost = w;
    edge[tol].next = head[u];
    head[u] = tol++;
}

int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    tol = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(n, 1);
    printf("%d\n", dist[n]);
    return 0;
}