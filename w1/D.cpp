#include <bits/stdc++.h>

using namespace std;

const int maxn = 500010;

struct node {
    int x, y;
    node(int x = 0, int y = 0) : x(x), y(y){};
    bool operator<(const node &a) const {
        return x < a.x || (!(a.x < x) && y < a.y);
    }
};

vector<int> G[maxn];
node a[maxn];
bool vis[maxn] = {0};
vector<node> es;
set<node> s;
int cnt;

inline void add(int x, int y) {
    G[x].push_back(y);
    G[y].push_back(x);
}

void dfs(int u, int fa) {
    // cout << u << " " << fa << endl;
    vis[u] = true;
    for (auto v : G[u]) {
        if (v != fa) {
            if (!vis[v]) {
                dfs(v, u);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        es.push_back(node(a[i].x, i));
        es.push_back(node(a[i].y, i));
    }
    sort(es.begin(), es.end());
    for (auto e : es) {
        if (cnt >= n)
            break;
        if (s.find(e) != s.end())
            s.erase(e);
        else {
            for (auto ee : s) {
                if (ee.x > a[e.y].y)
                    break;
                add(e.y, ee.y);
                cnt++;
                if (cnt >= n)
                    break;
            }
            s.insert(node(a[e.y].y, e.y));
        }
    }
    dfs(1, 0);
    int flag = false;
    if (cnt == n - 1) {
        flag = true;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == false) {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}