#include <bits/stdc++.h>

using namespace std;

int a[100002];
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int w = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= a[i - 1]) {
            cnt++;
        } else {
            w = i - 1;
        }
    }
    if (cnt == n) {
        printf("0\n");
    } else if (cnt < n - 1) {
        printf("-1\n");
    } else {
        if (a[n] <= a[1]) {
            printf("%d\n", n - w);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
