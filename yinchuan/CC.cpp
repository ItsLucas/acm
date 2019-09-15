#include <bits/stdc++.h>

using namespace std;

struct person {
    int id;
    int a;
    int b;
};
person aa[201], bb[201];
int tot[404];
inline bool cmpa(person x, person y) { return x.a > y.a; }
inline bool cmpb(person x, person y) { return x.b > y.b; }
inline bool cmp(int x, int y) { return x > y; }
int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        memset(tot, 0, sizeof(tot));
        if (n == 0)
            return 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &aa[i].a, &aa[i].b);
            bb[i].a = aa[i].a;
            bb[i].b = aa[i].b;
            tot[2 * i - 1] = aa[i].a;
            tot[2 * i] = aa[i].b;
            aa[i].id = i;
            bb[i].id = i;
        }
        sort(aa + 1, aa + n + 1, cmpa);
        sort(bb + 1, bb + n + 1, cmpb);
        sort(tot + 1, tot + n + 1, cmp);
        for (int i = 1; i <= 16; i++) {
        }
    }
}