#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 200023;

typedef long long ll;

ll p[maxn], q[maxn];

int main() {
    int n;
    cin >> n;
    ll sum = 0, minv = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> q[i];
        sum += q[i];
        if (sum < minv)
            minv = sum;
    }
    p[0] = 1 - minv;
    for (int i = 0; i < n - 1; i++) {
        p[i + 1] = p[i] + q[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (p[i] < 1 || p[i] > n) {
            flag = false;
        }
    }
    if (flag) {
        flag = set<ll>(p, p + n).size() == n;
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}