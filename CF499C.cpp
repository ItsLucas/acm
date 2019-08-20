#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct line {
    ll a, b, c;
} l[307];
int main() {
    ll x1, y1, x2, y2;
    int n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i].a >> l[i].b >> l[i].c;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (l[i].b != 0) {
            double yy1 = (l[i].a * x1 + l[i].c) * (-1.0) / l[i].b;
            double yy2 = (l[i].a * x2 + l[i].c) * (-1.0) / l[i].b;
            if ((yy1 > y1) ^ (yy2 > y2))
                cnt++;
        } else {
            double xx = (-1.0) * l[i].c / l[i].a;
            if ((x1 > xx) ^ (x2 > xx))
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}