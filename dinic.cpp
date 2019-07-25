#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;
const int inf = 0x7fffffff;
int n,m;

struct Edge {
    int v,w;
    Edge(int v=0,int w=0):v(v),w(w){};
};

vector<Edge> G[maxn];
int s,t,cnt;
vector<int> cur;
vector<int> dep;


inline void add(int u,int v,int w) {
    G[u].push_back(Edge(v,w));
    G[v].push_back(Edge(u,0));
}

bool bfs() {
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    dep.assign(n+1,0);
    dep[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto s : G[u]) {
            if(dep[s.v]==0 && s.w > 0) {
                printf("w %d %d\n",s.v,s.w);
                dep[s.v] = dep[u] + 1;
                Q.push(s.v);
            }
        }
    }
    printf("d %d\n",dep[t]);
    return dep[t];
}

int dfs(int u,int f) {
    if(u==t || f == 0) return f;
    int tmp = f;
    for(int &i = cur[u];i < G[u].size();i++) {
        Edge &e = G[u][i];
        if(dep[e.v] == dep[u] + 1 && e.w != 0) {
            int di = dfs(e.v,min(f,e.w));
            if(di > 0) {
                G[u][i].w -= di;
                G[u][i^1].w += di;
                printf("%d %d %d %d %d\n",u,i,i^1,G[u][i^1].v,G[u][i].v);
                f -= di;
                if(f==0) break;
            }
        }
    }
    return tmp - f;
}

int Dinic() {
    int Ans=0;
    while (bfs()) {
        cur.assign(n+1,0);
        int x=dfs(1,inf);
        printf("%d\n",x);
        Ans+=x;
    }
    return Ans;
}

int main() {
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    cout<<Dinic()<<endl;
    return 0;
}