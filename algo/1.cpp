#include <bits/stdc++.h>

static constexpr int maxn = 30;

using namespace std;
map<char, int> dict;
map<int, char> rdict;
int g[maxn][maxn], visit[maxn];
int n, m, t;
int Min = 99999;

int toi(char x) { return dict[x]; }
char toa(int x) { return rdict[x]; }
stack<int> st;

int h[100];
bool b[100];
int ans[100];
vector<int> G[100];
void add(int x, int y) {
    G[x].push_back(y);
    G[y].push_back(x);
}

void route(int v, int cnt) {
    cnt--;
    for (auto x : G[v]) {
        if (ans[x] == cnt) {
            cout << toa(x) << " ";
            if (cnt == 0)
                return;
            route(x, cnt);
        }
    }
}
void bfs(int u, int v) {
    b[u] = true;
    queue<int> Q;
    Q.push(u);
    while (Q.size()) {
        int tot = Q.front();
        Q.pop();
        for (auto x : G[tot]) {
            if (ans[x] == 0)
                ans[x] = ans[tot] + 1;
            if (ans[v] > 0) {
                cout << "BFS: " << ans[v] << endl;
                cout << toa(v) << " ";
                route(v, ans[v]);
                cout << toa(u) << endl;
                return;
            }
            if (!b[x]) {
                b[x] = true;
                Q.push(x);
            }
        }
    }
}

void dfs(int s, int r) {
    if (s == t) {
        if (r > Min) {
            return;
        } else {
            Min = r;
            while (!st.empty()) {
                int a = st.top();
                st.pop();
                cout << toa(a) << " ";
            }
            cout << "F"
                 << " " << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[s][i] != 0 && !visit[i]) {
            visit[i] = 1;
            st.push(i);
            dfs(i, r + g[s][i]);
            visit[i] = 0;
            st.pop();
        }
    }
}
int main() {
    // freopen("1.in", "r", stdin);
    cin >> n >> m;
    for (char i = '0'; i <= '9'; i++) {
        dict[i] = atoi(&i);
        rdict[atoi(&i)] = i;
    }
    int val = 10;
    for (char i = 'A'; i <= 'Z'; i++) {
        dict[i] = val;
        rdict[val] = i;
        val++;
    }
    for (int i = 1; i <= m; i++) {
        char a, b;
        cin >> a >> b;
        g[toi(a)][toi(b)] = 1;
        add(toi(a), toi(b));
    }
    visit[toi('F')] = 1;
    t = toi('M');
    dfs(toi('F'), 0);
    cout << "DFS: " << Min << endl;
    bfs(toi('F'), toi('M'));
    return 0;
}