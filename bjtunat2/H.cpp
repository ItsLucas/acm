#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll xx, yy, xx1, yy1, xx2, yy2;

int main() {
    cin >> yy >> xx;
    cin >> yy1 >> xx1 >> yy2 >> xx2;
    ll up = yy1 - 1;
    ll down = yy - yy2;
    ll left = xx1 - 1;
    ll right = xx - xx2;
    ll ans = 0;
    ans += (xx % 2) * up;
    ans += (xx % 2) * down;
    ans += (left % 2) * (yy2 - yy1 + 1);
    ans += (right % 2) * (yy2 - yy1 + 1);
    double ans2 = (double)ans;
    ans2 /= 2;
    cout << (ll)ceil(ans2) << endl;
    return 0;
}