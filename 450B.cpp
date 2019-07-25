#include <bits/stdc++.h>

using namespace std;

int f[6];
int mod = 1e9+7;

int main() {
    cin>>f[1]>>f[2];
    int n;
    cin>>n;
    f[3] = f[2] - f[1];
    f[4] = -f[1];
    f[5] = -f[2];
    f[0] = f[1] - f[2];
    if(f[n%6]==-mod) {
        cout<<0<<endl;
    }
    else if(f[n%6]<0) {
        cout<<mod-((-f[n%6])%mod)<<endl;
    }
    else {
        cout<<f[n%6]%mod<<endl;
    }
    return 0;
}