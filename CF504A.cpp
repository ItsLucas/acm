#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 65537;

struct node {
    int u, v;
    node(int u = 0, int v = 0) : u(u), v(v){};
};

vector<node> G;

int d[maxn], s[maxn];

int main() {
    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> s[i];
        if (d[i] == 1) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (d[u] == 0)
            continue;
        d[u]--;
        int v = s[u];
        s[u] = 0;
        G.push_back(node(u, v));
        s[v] ^= u;
        d[v]--;
        if (d[v] == 1) {
            Q.push(v);
        }
    }
    cout << G.size() << endl;
    for (auto i : G) {
        cout << i.u << " " << i.v << endl;
    }
    return 0;
}