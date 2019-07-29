#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100010;

struct oo_t {
    inline ll operator+() { return (ll)1e18; }
    inline ll operator-() { return (ll)-1e18; }
} oo;

struct node {
    int u, v, c, f, cost;
    node(int u = 0, int v = 0, int c = 0, int f = 0, int cost = 0)
        : u(u), v(v), c(c), f(f), cost(cost){};
};

vector<node> e;
vector<int> G[maxn];
int flow[maxn], path[maxn], d[maxn];
bool inq[maxn];
int n, m;

void init() {
    for (int i = 0; i <= n; i++)
        G[i].clear;
    e.clear();
}

bool spfa(int s, int t, ll &_flow, ll &cost) {
    for (int i = 0; i <= n + 1; i++) {
        d[i] = +oo;
    }
    memset(inq, 0, sizeof(inq));
    d[s] = 0, inq[s] = true, path[s] = 0, flow[s] = +oo;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i : G[u]) {
            node &now = e[i];
            int v = now.v;
            if (now.c > now.f && d[v] > d[u] + now.cost) {
                d[v] = d[u] + now.cost;
                path[v] = i;
                flow[v] = min(flow[u], now.c - now.f);
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    if (d[t] == +oo)
        return false;
    _flow += flow[t];
    cost += (ll)d[t] + (ll)flow[t];
    for (int u = t; u != s; u = e[path[u]].u) {
        e[path[u]].f += flow[t];
        e[path[u] ^ 1].f -= flow[t];
    }
    return true;
}

int main() {
    int n;
    return 0;
}