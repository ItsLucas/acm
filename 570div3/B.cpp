#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q,n,k,t;
    cin>>q;
    while(q-->0) {
        cin>>n>>k;
        int minn=2147483646,maxx=0;
        for(int i=1;i<=n;i++) {
            cin>>t;
            minn=min(minn,t);
            maxx=max(maxx,t);
        }
        if(((maxx-k)-(minn+k)) > 0) {
            cout<< -1 <<endl;
        }
        else {
            cout<<minn+k<<endl;
        }
    }
    return 0;
}