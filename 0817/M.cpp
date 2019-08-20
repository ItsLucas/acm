#include <bits/stdc++.h>

using namespace std;

char ss[11];
int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        unordered_map<string, double> mp;
        string s;
        double tt;
        int n, m;
        scanf("%d %d", &n, &m);
        mp["JD"] = 1.0f;
        for (int i = 1; i <= n; i++) {
            scanf("%s", ss);
            s = string(ss);
            scanf("%lf", &tt);
            mp[s] = tt;
            // cout << s << " " << t << endl;
        }
        double tot = 0.0f;
        for (int i = 1; i <= m; i++) {
            scanf("%lf", &tt);
            scanf("%s", ss);
            s = string(ss);
            tot += mp[s] * tt;
        }
        printf("%.6lf\n", tot);
    }
    return 0;
}