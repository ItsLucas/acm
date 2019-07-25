#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

vector<int> G[maxn];
int dep[maxn],siz[maxn],anc[maxn][30];
int in[maxn],out[maxn],t=0,n;

void dfs(int p,int fa,int d) {
    dep[p] = d;
    siz[p] = 1;
    in[p] = t++;
    anc[p][0] = fa;
    for(int i=1;i<30;i++) {
        anc[p][i] = anc[anc[p][i-1]][i-1];
    }
    for(int i : G[p]) {
        if(i != fa) {
            dfs(i,p,d+1);
            siz[p] += siz[i];
        }
    }
    out[p] = t++;
}

inline bool isanc(int a,int b) {
    return in[a] <= in[b] && out[b] <= out[a];
}

int up(int a,int b) {
    for (int i = 29; i >= 0; i--) {
        if (!isanc(anc[a][i], b)) {
            a = anc[a][i];
        }
    }
    return a;
}

int lca(int a,int b) {
    int ret = -1;
    if(isanc(a,b)) ret=a;
    else if(isanc(b,a)) ret=b;
    else ret=anc[up(a,b)][0];
    return ret;
}

int query(int a,int b) {
    int l = lca(a,b);
    int ret = -1;
    if(a==b) ret = n;
    else if(dep[a] - dep[l] == dep[b] - dep[l]) {
        a = up(a,l);
        b = up(b,l);
        ret = n - siz[a] - siz[b];
    }
    else {
        if(dep[a] < dep[b]) swap(a,b);
        int to = a;
        int dist = dep[a] + dep[b] - 2 * dep[l];
        if(dist%2==1) ret=0;
        else {
            dist /= 2;
            for (int i = 29; i >= 0; i--) {
                if (dep[a] - dep[anc[to][i]] < dist) {
                    to = anc[to][i];
                }
            }
 
            int m = anc[to][0];
            ret = siz[m] - siz[to];
        }
    }
    return ret;
}

int main() {
    cin>>n;
    int a,b;
    for(int i=1;i<=n-1;i++) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,1,0);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }
    return 0;
}