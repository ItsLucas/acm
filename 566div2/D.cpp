#include <bits/stdc++.h>

using namespace std;

vector<int> v[100010];
int deg[100010];

void dfs(int fa) {
    for(int i : v[fa]) {
        deg[fa]++;
        
    }
}

int main() {
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        v[a].push_back(b);
    }

    return 0;
}