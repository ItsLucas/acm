#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, tmp;
ll ans;
void solve() {
    cin >> n >> k;
    if (n <= 2 * k) {
        cout << 10 << endl;
    } else {
        // cerr<<ceil(1.0*n/k)<<endl;
        tmp = (int)ceil(1.0 * n / k); //+(int)floor(n/(2*k));
        cout << 1ll * tmp * 5 << endl;
    }
    // if(n==)
}

int main() {
    solve();
    return 0;
}