#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int tree[N<<2];

void pushup(int root) {
    tree[root] = tree[root*2] + tree[root*2+1];
}

void build(int l,int r,int root) {
    if(l==r) {
        tree[root] = 1;
        return;
    }

    int mid = (l+r) / 2;
    build(l,mid,root*2);
    build(mid+1,r,root*2+1);

    pushup(root);
}

void update(int p,int v,int l,int r,int root) {
    if(l==r) {
        tree[root]+=v;
        return;
    }
    int mid = (l+r) / 2;
    if(p > mid) {
        update(p,v,mid+1,r,root*2+1);
    }
    else {
        update(p,v,l,mid,root*2);
    }
    pushup(root);
}

int query(int L,int R,int l,int r,int root) {
    if(L <= l && r <= R){
        return tree[root];
    }
    else {
        int res = 0;
        int mid = (l+r) / 2;
        if(L<=mid) {
            res += query(L,R,l,mid,root*2);
        }
        if(R > mid) {
            res += query(L,R,mid+1,r,root*2+1);
        }
        return res;
    }
}

int main() {
    int n;
    cin>>n;
    build(1,n,1);
    int l,r;
    cin>>l>>r;
    cout<<query(l,r,1,n,1)<<endl;
    return 0;
}