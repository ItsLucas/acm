#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1e6 + 5;

int n, maxx;
int a[maxn], p[maxn], sum[maxn], ans[maxn];

int work(int x) {
    if (x < maxx)
        return -1;
    if (ans[x])
        return ans[x];
    int ret = 0, i = 0;
    while (i < n) {
        ret += x;
        ret = min(ret, 1000000);
        i = p[ret];
        ret = sum[i];
        ans[x]++;
    }
    return ans[x];
}

int main() {
    int q, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        sum[i] = sum[i - 1] + a[i];
        for (int j = sum[i - 1]; j < sum[i]; j++) {
            p[j] = i - 1;
        }
    }
    for (int i = sum[n]; i <= maxn; i++) {
        p[i] = n;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        int r = work(x);
        if (r == -1)
            cout << "Impossible" << endl;
        else
            cout << r << endl;
    }
    return 0;
}