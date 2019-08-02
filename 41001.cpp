#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

typedef long long ll;
int fa[maxn];
int ans[maxn];
int n;

inline int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }
void merge(int a, int b) { fa[find(a)] = find(b); }

struct Edge {
    int from, to, val;
    Edge(int from = 0, int to = 0, int val = 0)
        : from(from), to(to), val(val){};
    inline bool operator<(const Edge &a) const { return val < a.val; }
};

vector<Edge> es;

ll kruscal() {
    sort(es.begin(), es.end());
    iota(fa, fa + n + 1, 0);
    ll ans = 0;
    for (Edge &e : es) {
        if (find(e.from) != find(e.to)) {
            merge(e.from, e.to);
            ans += e.val;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        bool flag = false;
        // es.clear();
        memset(ans, 0, sizeof(ans));
        scanf("%d", &n);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; (1 << j) <= n; j++) {
                // printf("\n##%d %d %d\n", i, ((1 << j) - 1), i & (1 << j));
                /*
                if (i == ((1 << j) - 1)) {
                    ans[i] = 1;
                    es.push_back(Edge(i, 1, 1));
                    es.push_back(Edge(1, i, 1));
                    break;
                }
                */

                if ((i & (1 << j)) == 0) {
                    ans[i] = (1 << j);
                    // es.push_back(Edge(i, j, 0));
                    // es.push_back(Edge(j, i, 0));
                    break;
                }
            }
            if (!ans[i]) {
                flag = true;
                ans[i] = 1;
                // es.push_back(Edge(i, 1, 1));
                // es.push_back(Edge(1, i, 1));
            }
            // printf("%d^^\n", ans[i]);
        }
        printf("%d\n", flag);
        for (int i = 2; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}