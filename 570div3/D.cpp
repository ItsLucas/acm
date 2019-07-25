#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int c[200010];
vector<int> v[200010];
int main() {
    int q,maxc=0;
    cin>>q;
    while(q-->0) {
        for(int i=1;i<=200010;i++) {
            v[i].clear();
        }
        maxc = 0;
        memset(c,0,sizeof(c));
        int n,t;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>t;
            c[t]++;
            maxc = max(c[t],maxc);
        }
        for(int i=1;i<=n;i++) {
            if(v[c[i]].empty())
                v[c[i]].push_back(i);
            else {
                int j = i;
                j--;
                while(j >= 1) {
                    //cout<<"while"<<endl;
                    if(v[j].empty()) {
                        v[j].push_back(i);
                        break;
                    }
                    else j--;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=maxc;i++) {
            if(!v[i].empty()) {
                ans += i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}