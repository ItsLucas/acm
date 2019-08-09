#include <bits/stdc++.h>

using namespace std;
struct node {
    int x, y;
};

node s[100005];

bool cmp(node &a, node &b) { return a.y < b.y; }

int main() {
    long long n, r, avg, k, sum, ans;
    cin >> n >> r >> avg;
    sum = ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i].x >> s[i].y;
        sum += s[i].x;
    }
    sort(s, s + n, cmp);
    k = avg * n - sum;
    if (k <= 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n && k > 0; i++) {
        if (k <= (r - s[i].x)) {
            ans += (k * s[i].y);
            k = 0;
        } else {
            ans += ((r - s[i].x) * s[i].y);
            k -= (r - s[i].x);
        }
    }
    cout << ans << endl;

    return 0;
}