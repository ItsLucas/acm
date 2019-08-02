#include <bits/stdc++.h>
#define nop (void)0
using namespace std;

static constexpr int maxn = 1001;

int a[maxn];
map<int, int> mp;

inline void lock(int x) { mp[x]--; }

inline void res(int x) { mp[x]++; }

struct oo_t {
    inline long long operator+() { return 1e18; }
    inline long long operator-() { return -1e18; }
} oo;

int c(int a, int b) {
    int ret = 0;
    if (mp[a + b]) {
        lock(a + b);
        ret = c(b, a + b) + 1;
        res(a + b);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp[0] == n) {
        cout << n << endl;
        return 0;
    }
    sort(a, a + n);
    int tp = unique(a, a + n) - a;
    int ans = 0;
    for (int i = 0; i < tp; i++) {
        for (int j = 0; j < tp; j++) {
            if (i == j && mp[a[i]] == 1) {
                continue;
            }
            lock(a[i]);
            lock(a[j]);
            ans = max(ans, c(a[i], a[j]) + 2);
            res(a[i]);
            res(a[j]);
        }
    }
    cout << ans << endl;
    return 0;
}