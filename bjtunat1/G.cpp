#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7fffffff;
const int maxn = 1e5 + 50;
const double INFF = 1.0 * 1e18;
const double eps = 1e-8;
struct MEdge {
    int from, to, cap;
    double cost;
    MEdge(int from, int to, int cap, double cost)
        : from(from), to(to), cap(cap), cost(cost) {}
};

struct MCMF {
    int n, s, t, flow;
    double cost;
    vector<MEdge> es;
    vector<vector<int>> G;
    vector<double> d;
    vector<int> p, a; // dis, prev, add
    deque<bool> in;

    MCMF(int n, int s, int t)
        : n(n), s(s), t(t), flow(0), cost(0.0), G(n + 1), p(n + 1), a(n + 1) {}

    void add_edge(int u, int v, int cap, double cost) {
        G[u].push_back(es.size());
        es.emplace_back(u, v, cap, cost);
        G[v].push_back(es.size());
        es.emplace_back(v, u, 0, -cost);
    }

    bool spfa() {
        d.assign(n + 1, INFF);
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
        return d[t] != INFF;
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

int ma[105][105];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ma[i][j];
        }
    }
    int s = 0;
    int tot = n * (n + 2) + 2;
    int t = tot - 1;
    MCMF mc = MCMF(tot, s, t);
    for (int i = 1; i <= n; i++) {
        mc.add_edge(s, n * n + i, 1, 0.0);
    }
    for (int i = 1; i <= n; i++) {
        mc.add_edge(n * n + n + i, t, 1, 0.0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mc.add_edge(n * n + i, n * (j - 1) + i, 1, 0.0);
            mc.add_edge(n * (j - 1) + i, n * n + n + j, 1, -log10(ma[j][i]));
        }
    }
    mc.solve();
    for (int i = n * n + 1; i <= n * n + n; i++) {
        for (auto ii : mc.G[i]) {
            MEdge e = mc.es[ii];
            if (e.cap == 0) {
                if (i == n * n + n)
                    cout << (e.to - 1) / n + 1;
                else
                    cout << (e.to - 1) / n + 1 << " ";
            }
        }
    }
}