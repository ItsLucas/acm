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

void dfs(graph G, int u, int v, int w, bool flag) {
    anode *x;
    int n = 0;
    n++;           // front
    vis[u] = true; // mark visited
    if (u == v && n == w + 1)
        flag = true; // found
    else {
        x = G.vs[u].first; // get v.x
        while (!flag &&
               x != nullptr) { // iterate through all vertices next to it
            if (!vis[x->v]) {
                dfs(G, x->v, v, w, flag); // recursive dfs
            }
            x = x->next; // next
        }
    }
    vis[u] = false; // back
    n--;            // back
}