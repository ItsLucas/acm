#include <bits/stdc++.h>
#define nop (void)0
using namespace std;

static constexpr int maxn = 101;

struct node {
    int c, cnt;
    node(int c = 0, int cnt = 0) : c(c), cnt(cnt){};
};

vector<node> a;

struct oo_t {
    inline long long operator+() { return 1e18; }
    inline long long operator-() { return -1e18; }
} oo;

int main() {
    int n, k, x, t;
    cin >> n >> k >> x;
    a.push_back(node(-233, 0));
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t != a.back().c) {
            a.push_back(node(t, 1));
        } else {
            a.back().cnt++;
        }
    }
    int ans = 0;
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i].c == x && a[i].cnt >= 2) {
            int tt = a[i].cnt;
            for (int l = i - 1, r = i + 1;; l--, r++) {
                if (a[l].c != a[r].c || a[l].cnt + a[r].cnt < 3)
                    break;
                tt += a[l].cnt + a[r].cnt;
            }
            ans = max(ans, tt);
        }
    }
    cout << ans << endl;
    return 0;
}
