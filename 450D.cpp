#include<bits/stdc++.h>
using namespace std;
 
const int maxn=300050;
typedef long long ll;

struct node {
    long long v,w;
    node(long long v=0,long long w=0): v(v), w(w){};
    inline bool operator<(const node &a) const { 
        return w > a.w; 
    }
};

 
const ll INF=1e18;
vector<node> G[maxn];
ll train[maxn];
bool vis[maxn];
int istrain[maxn];
ll dis[maxn];
ll n,m,k;
int ans=0;
 
void dijkstra(int s) {
    memset(vis,0,sizeof(vis));
    priority_queue<node> Q;
    for(int i=1; i<=n; i++){
        dis[i]=INF;
        if(train[i]!=0){
            dis[i]=train[i];
            Q.push(node(i,train[i]));
        }
    }
    dis[s]=0;
    Q.push(node(s,0));
    while(!Q.empty()) {
        node u=Q.top();
        Q.pop();
        ll v = u.v;
        if(vis[v]) continue;
        vis[v]=true;
        for(auto i : G[v]) {
            ll v2=i.v;
            ll w=i.w;
            if(!vis[v2]&&dis[v] + w<=dis[v2]) {
                if(istrain[v2]==1) {
                    istrain[v2]=-1;
                    ans++;
                }
                if(!vis[v2]&&dis[v]+w<dis[v2]) {
                    dis[v2]=dis[v]+w;
                    Q.push(node(v2,dis[v2]));
                }
            }
        }
    }
}
 
int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(node(v,w));
        G[v].push_back(node(u,w));
    }
    for(int i=1; i<=k; i++) {
        ll a,b;
        cin>>a>>b;
        if(train[a]) {
            train[a]=min(train[a],b);
            ans++;
        } else {
            istrain[a]=true;
            train[a]=b;
        }
    }
    dijkstra(1);
    cout<<ans<<endl;
    return 0;
}