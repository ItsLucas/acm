// modification
#include <bits/stdc++.h>

const int maxn = 5e2 + 10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int a[1010][1010];
ll n, m, k, p;
ll sumx[1010];
ll sumy[1010];

ll dpx[1000010];
ll dpy[1000010];

priority_queue<ll> sx, sy; //有序数组
int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sumy[j] += a[i][j];
            sumx[i] += a[i][j];
        }
    }
    //行与列分开求
    for (int i = 0; i < n; i++)
        sx.push(sumx[i]);
    for (int j = 0; j < m; j++)
        sy.push(sumy[j]);

    dpx[0] = dpy[0] = 0;
    for (int i = 1; i <= k; i++) {
        ll t1 = sx.top();
        sx.pop();
        ll t2 = sy.top();
        sy.pop();
        dpx[i] = dpx[i - 1] + t1;
        dpy[i] = dpy[i - 1] + t2;
        sx.push(t1 - m * p);
        sy.push(t2 - n * p);
    }
    //最后利用k遍历
    ll re = dpx[0] + dpy[k];
    for (int i = 1; i <= k; i++) {
        re = max(re, (dpx[i] + dpy[k - i] - (ll)(i * (k - i) * p)));
    }

    cout << re << endl;
    return 0;
}
