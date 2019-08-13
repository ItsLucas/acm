#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[10001][10001];

const int INF = 0x7fffffff;

struct MEdge {
    int from, to, cap, cost;
    MEdge(int from, int to, int cap, int cost)
        : from(from), to(to), cap(cap), cost(cost){};
};

struct Edge {
    int x, y;
};
Edge HH[100010], MM[100010];

struct MCMF {
    int n, s, t, flow, cost;
    vector<MEdge> es;
    vector<vector<int>> G;
    vector<int> d, p, a; // dis, prev, add
    deque<bool> in;

    MCMF(int n, int s, int t)
        : n(n), s(s), t(t), flow(0), cost(0), G(n + 1), p(n + 1), a(n + 1) {}

    void add_edge(int u, int v, int cap, int cost) {
        G[u].push_back(es.size());
        es.emplace_back(u, v, cap, cost);
        G[v].push_back(es.size());
        es.emplace_back(v, u, 0, -cost);
    }

    bool spfa() {
        d.assign(n + 1, INF);
        in.assign(n + 1, false);
        d[s] = 0;
        in[s] = 1;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in[u] = false;
            for (int &i : G[u]) {
                MEdge &e = es[i];
                if (e.cap && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = i;
                    a[e.to] = min(a[u], e.cap);
                    if (!in[e.to]) {
                        q.push(e.to);
                        in[e.to] = true;
                    }
                }
            }
        }
        return d[t] != INF;
    }

    void solve() {
        while (spfa()) {
            flow += a[t];
            cost += a[t] * d[t];
            int u = t;
            while (u != s) {
                es[p[u]].cap -= a[t];
                es[p[u] ^ 1].cap += a[t];
                u = es[p[u]].from;
            }
        }
    }
};

int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        int ch = 0, cm = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'H') {
                    HH[ch].x = i;
                    HH[ch++].y = j;
                } else if (map[i][j] == 'm') {
                    MM[cm].x = i;
                    MM[cm++].y = j;
                }
            }
        }
        int b = 0;
        int e = 2 * ch + 1;
        MCMF mcmf = MCMF(n + 2, b, e);
        for (int i = 0; i < cm; i++) {
            mcmf.add_edge(b, i + 1, 1, 0);
            for (int j = 0; j < ch; j++) {
                int tt = abs(HH[i].x - MM[j].x) + abs(HH[i].y - MM[j].y);
                mcmf.add_edge(i + 1, j + 1 + ch, 1, tt);
            }
            mcmf.add_edge(i + 1 + ch, e, 1, 0);
        }
        printf("%d\n", mcmf.flow);
    }
}