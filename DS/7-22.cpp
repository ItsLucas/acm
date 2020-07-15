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

void dfs(graph G, int u, int v, bool flag) {
    anode *x;
    vis[u] = true; // mark visited
    if (u == v)
        flag = true; // found
    else {
        x = G.vs[u].first; // get v.x
        while (!flag &&
               x != nullptr) { // iterate through all vertices next to it
            if (!vis[x->v]) {
                dfs(G, x->v, v, flag); // recursive dfs
            }
            x = x->next; // next
        }
    }
}