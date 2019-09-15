#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stu {
    int id;
    ll a;
    ll b;
    inline bool operator<(const stu &s) const { return a < s.a; }
};

vector<stu> A;
vector<stu> B;
ll b[100010];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        ll x, y;
        scanf("%d", &n);
        A.clear();
        B.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &x, &y);
            A.push_back({i, x, y});
            B.push_back({i, y, x});
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0; i < n; i++) {
            b[i] = B[i].a;
        }
        ll maxb = -233, ans = LONG_LONG_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (A[i].a <= maxb) {
                ans = min(ans, maxb - A[i].a);
                break;
            }
            ll val = LONG_LONG_MAX;
            int pos = lower_bound(b, b + n, A[i].a) - b;
            int start = max(0, pos - 2);
            int end = min(++pos, n - 1);
            for (int j = start; j <= end; j++) {
                if (A[i].id != B[j].id) {
                    val = min(val, abs(A[i].a - B[j].a));
                }
            }
            ans = min(ans, val);
            if (ans == 0) {
                break;
            }
            maxb = max(maxb, A[i].b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}