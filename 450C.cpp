#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, k;
    cin>>n>>m>>k;
    ll kk = k+1;
    if (k>n+m-2) {
        cout<<-1<<endl;
    }
    else {
        ll maxx = max(m,n);
        if (maxx >= kk) {
            ll ans1 = m * (n / kk);
            ll ans2 = n * (m / kk);
            cout<<max(ans1,ans2)<<endl;
        }
        else {
            if (n < m) {
                k -= m-1;
                n /= k+1;
                cout<<n<<endl;
            }
            else {
                k -= n-1;
                m /= k+1;
                cout<<m<<endl;
            }
        }
    }
}