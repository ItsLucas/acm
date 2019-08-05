#include <bits/stdc++.h>
using namespace std;
int T;
int n, k;
int a[22];
int vis[22];
long long sum;
bool judge(int y) {
    int x = n - y;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && y != 1) {
            a[y] = i;
            break;
        }
    }
    vis[a[y]] = 1;
    sum = 1;
    for (int i = 1; i <= x; i++) {
        sum *= i;
        if (sum >= k)
            return 1;
    }
    return 0;
}
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &n, &k);
        for (int j = 1; j <= n; j++)
            vis[j] = 0;
        a[1] = n;
        for (int j = 2; j <= n; j++)
            a[j] = j - 1;
        for (int j = 1; j < n; j++) {
            if (judge(j))
                continue;
            if (j == 1) {
                vis[a[1]] = 0;
                while (sum < k) {
                    k -= sum;
                    a[1]--;
                }
                vis[a[1]] = 1;
            } else {
                int p = 0;
                while (sum < k) {
                    p++;
                    if (vis[p])
                        continue;
                    k -= sum;
                }
                while (vis[p])
                    p++;
                vis[a[j]] = 0;
                a[j] = p;
                vis[p] = 1;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                a[n] = j;
                break;
            }
        }
        for (int j = 1; j <= n; j++)
            printf("%d ", a[j]);
        printf("\n");
    }
}