#include <bits/stdc++.h>

using namespace std;

const int maxn = 300010;
vector<int> G[maxn];

int f[maxn][27];
int d[maxn];
char s[maxn];
queue<int> q;

inline int toi(char s) { return s - 'a'; }

int main() {
    int n, m;
    cin >> n >> m;
    scanf("%s", s + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        d[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
            f[i][toi(s[i])] = 1;
        }
    }
    int n2 = n;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        n2--;
        for (auto i : G[now]) {
            for (int j = 0; j < 26; j++) {
                f[i][j] = max(f[i][j], f[now][j] + (toi(s[i]) == j));
            }
            d[i]--;
            if (d[i] == 0)
                q.push(i);
        }
    }
    if (n2 > 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}