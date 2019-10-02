#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int calc(ll n) {
    if (!n)
        return 0;
    return calc(n / 2) + (n & 1);
}
void solve() {
    ll n;
    cin >> n;
    cout << (ll)pow(2, calc(n)) << endl;
    // if (n & 1)
    //    puts("4");
    // else
    //    puts("2");
}
int main() {
    solve();

    return 0;
}