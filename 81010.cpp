#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 1e-6;

struct team {
    char name[11];
    int p, t;
    inline bool operator<(const team &b) const {
        if (p > b.p) {
            return true;
        } else if (p < b.p) {
            return false;
        } else {
            return t < b.t;
        }
    }
} tem[100010];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        double d;
        scanf("%d %lf", &n, &d);
        d = 10 * d / 100;
        double tmp = (double)n * d;
        for (int i = 1; i <= n; i++) {
            scanf("%s", tem[i].name);
            scanf("%d %d", &tem[i].p, &tem[i].t);
            // printf("%s %d %d\n", tem[i].name, tem[i].p, tem[i].t);
        }
        // cout << tmp << " " << floor(tmp) << endl;
        if (tmp - floor(tmp) != (double)0.5) {
            printf("Quailty is very great\n");
            continue;
        }
        sort(tem + 1, tem + n + 1);
        printf("%s\n", tem[(int)floor(tmp) + 1].name);
    }
    return 0;
}
