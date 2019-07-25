#include <bits/stdc++.h>

using namespace std;

struct child {
    int id;
    int want;
    child(int id=0,int want=0):id(id),want(want){};
};

int n,m;
queue<child> q;

int main() {
    cin>>n>>m;
    int t;
    for(int i=1;i<=n;i++) {
        cin>>t;
        q.push(child(i,t));
    }
    int lastid;
    while(!q.empty()) {
        child c = q.front();
        q.pop();
        lastid = c.id;
        if(c.want <= m) continue;
        else {
            c.want -= m;
            q.push(child(c.id,c.want));
        }
    }
    cout<<lastid<<endl;
    return 0;
}