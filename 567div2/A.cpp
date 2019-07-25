#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long x,y,z;
    cin>>x>>y>>z;
    long long sum = x + y;
    cout<<sum/z<<" ";
    long long xr = x % z;
    long long yr = y % z;
    if(xr+yr<z) {
        cout<<0<<endl;
        return 0;
    }
    if(xr>yr) cout<<z-xr<<endl;
    else cout<<z-yr<<endl;
    return 0;
}