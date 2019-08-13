#include <bits/stdc++.h>

using namespace std;

int f[10010];
bool vis[10010];

int find(int x) {
    if (f[x] == x)
        return x;
    f[x] = find(f[x]);
    return f[x];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= 10000; i++) {
        f[i] = i;
        vis[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        a = find(a);
        b = find(b);
        if (a == b)
            vis[a] = true;
        if (a > b)
            f[b] = a;
        else
            f[a] = b;
    }
    int i;
    for (i = 1; i <= 10000; i++) {
        if (find(i) == i && vis[i] == false)
            break;
    }
    printf("%d\n", i - 1);
    return 0;
}
