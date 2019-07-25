#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin>>q;
    while(q-->0) {
        long long k,n,a,b;
        cin>>k>>n>>a>>b; 
        k -= b * n;
        if(k < 1) {
            cout<< -1 <<endl;
            continue;
        }
        k--;
        long long r = k / (a-b);
        cout<<min(r,n)<<endl;
    }
    return 0;
}