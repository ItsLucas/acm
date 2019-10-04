#include <bits/stdc++.h>
#define N 210000
struct sl {
    int x, id;
} t[N];
int a[100], i, j, n, m, k, l, o, ans[N];
char c;
int get(int x) {
    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans += x % 10, x /= 10;
    for (int i = 1; i <= 3; i++)
        ans -= x % 10, x /= 10;
    return std::abs(ans);
}
bool cmp(sl x, sl y) { return x.x < y.x; }
int main() {
    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        int x = 0;
        for (j = 1; j <= 6; j++) {
            scanf("%c", &c);
            x = x * 10 + c - '0';
        }
        scanf("\n");
        t[i].x = x;
        t[i].id = i;
    }
    std::sort(t + 1, t + n + 1, cmp);
    l = 1;
    for (i = 0; i <= 999999; i++) {
        if (l > n)
            break;
        int x = get(i);
        a[x]++;
        while (i == t[l].x && l <= n) {
            int p = get(t[l].x);
            for (j = 0; j < p; j++)
                ans[t[l].id] += a[j];
            l++;
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}