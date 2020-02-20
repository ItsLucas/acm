#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000010];
long long cnt[1000010];
int op[1000010][3];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        int t;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            cnt[i] = 0;
            int o;
            scanf("%d", &o);
            if (o == 1) {
                op[i][0] = 1;
                int k;
                scanf("%d", &k);
                for (int j = 0; j < k; j++) {
                    scanf("%d", &t);
                    v[i].push_back(t);
                }
            } else {
                op[i][0] = 2;
                scanf("%d %d", &op[i][1], &op[i][2]);
            }
        }
        cnt[n] = 1;
        for (int i = n; i >= 1; i--) {
            if (op[i][0] == 2) {
                cnt[op[i][1]] += cnt[i];
                cnt[op[i][2]] += cnt[i];
            }
        }
        long long x = 0, w = 0, len = 0;
        for (int i = 1; i <= n; i++)
            if (op[i][0] == 1 && cnt[i] != 0)
                for (auto u : v[i]) {
                    if (x == 0)
                        x = u, w += cnt[i];
                    else if (x == u)
                        w += cnt[i];
                    else {
                        w -= cnt[i];
                        if (w < 0)
                            x = u, w = -w;
                    }
                    len += cnt[i];
                }
        w = 0;
        for (int i = 1; i <= n; i++) {
            if (op[i][0] == 1 && cnt[i] != 0) {
                for (auto u : v[i]) {
                    if (u == x) {
                        w += cnt[i];
                    }
                }
            }
        }
        if (w > len - w)
            printf("%lld\n", (len - w) * 2);
        else
            printf("%lld\n", len);
    }
    return 0;
}