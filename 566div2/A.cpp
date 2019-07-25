#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin>>n;
    if(n%2==1LL) cout<<0<<endl;
    else printf("%lld\n",1LL<<(n/2));
    return 0;
}