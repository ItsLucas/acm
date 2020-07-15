#include <queue>

using namespace std;

struct anode {
    int v;
    anode *next;
};

typedef struct vnode {
    int data;
    anode *first;
} list[2000];

struct graph {
    list vs;
    int n, m;
};
bool vis[2000];

bool bfs(graph G, int u, int v) {
    queue<int> q;
    anode *x;
    q.push(u);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        vis[k] = true;
        for (x = G.vs[k].first; x; x = x->next) {
            int v2 = x->v;
            if (v2 == v) {
                if (!vis[v2]) {
                    q.push(v2);
                }
            }
        }
    }
    return vis[v] && vis[u];
}