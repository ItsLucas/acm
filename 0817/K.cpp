#include <bits/stdc++.h>
using namespace std;
int T;
int a, b;
int x, y;
int N;
long long sum;
int f[20], ans, vis[20];
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &a, &b, &N);
        sum = 0;
        ans = 0;
        x = 0;
        y = 0;
        int flag = 0;
        for (int j = 0; j <= 9; j++)
            f[j] = 0;
        while (sum <= N) {
            x++;
            sum = x * x * a + x * b;
            if (sum > N)
                break;
            flag = 1;
            for (int j = 0; j <= 9; j++)
                vis[j] = 0;
            while (sum) {
                vis[sum % 10]++;
                sum /= 10;
            }
            y = 0;
            for (int j = 0; j <= 9; j++)
                if (vis[y] < vis[j])
                    y = j;
            for (int j = 0; j <= 9; j++)
                if (vis[j] == vis[y])
                    f[j]++;
        }
        for (int j = 0; j <= 9; j++)
            if (f[ans] < f[j])
                ans = j;
        if (flag)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}