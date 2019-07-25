#include <bits/stdc++.h>

using namespace std;

long long ans = 1;
const long long mmod = 1e6+3;
int main() {
    long long n;
    cin>>n;
    if(n==0) ans=0;
    if(n >= mmod) ans=0;
    else for(int i=1;i<=n;i++) {
        ans *=i;
        ans %=mmod;
    }
    cout<<ans<<endl;
    return 0;
}