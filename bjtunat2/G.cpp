#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
struct edge {
    int a, b;
} t[maxn], ans[maxn];
int cnt[maxn];
int n;
struct dat {
    int c, v;
    dat(){};
    dat(int c, int v) : c(c), v(v){};
    inline bool operator<(const dat &d) const {
        if (c == d.c) {
            return v < d.v;
        }
        return c > d.c;
    }
};
priority_queue<dat> Q;
void solve() {
    // cin>>a>>b;
    bool flag = 1;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> t[i].a >> t[i].b;
        if (t[i].a > t[i].b) {
            swap(t[i].a, t[i].b);
        }
        ++cnt[t[i].a];
        if (t[i].b != n)
            flag = 0;
    }
    for (int i = 1; i < n; ++i) {
        Q.push(dat(cnt[i], i));
    }
    for (int i = n - 1, tp = 0, b = n; i; --i) {
        if (cnt[i] > 0) {
            for (dat u; cnt[i] > 1; --cnt[i]) {
                u = Q.top();
                Q.pop();
                // cerr << u.second << " " << cnt[i] << endl;
                if (u.c != 0) {
                    flag = 0;
                    break;
                }
                if (u.v >= i) {
                    flag = 0;
                    break;
                }
                ans[++tp].a = u.v;
                ans[tp].b = b;
                b = u.v;
            }
            ans[++tp].a = i;
            ans[tp].b = b;
            b = i;
        }
    }
    if (!flag) {
        puts("NO");
        return;
    } else {
        puts("YES");
        for (int i = 1; i < n; ++i) {
            printf("%d %d\n", ans[i].a, ans[i].b);
        }
    }
}
int main() {
    solve();

    return 0;
}