#include <iostream>
#include <bitset>

using namespace std;

string a,b;
int d[1000010];
int odd[1000010];

int main() {
    cin>>a;
    cin>>b;
    int la = a.length();
    int lb = b.length();
    for(int i=1;i<=lb;i++) {
        d[lb] += (a[i]!=a[i-1]);
    }
    for(int i=lb+1;i<la;i++) {
        d[i]=d[i-1]-(a[i-lb-1] != a[i-lb])+(a[i]!=a[i-1]);
    }
    for(int i=0;i<lb;i++) {
        if(a[i]!=b[i]) {
            odd[lb-1]=(!odd[lb-1]);
        }
    }
    int ans = 0;
    if(odd[lb-1]==0) ans++;
    for(int i=lb;i<la;i++) {
        odd[i]=((odd[i-1]+d[i])&1);
        if(odd[i]==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}