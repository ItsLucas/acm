#include <bits/stdc++.h>
#define N 51000
using namespace std;
struct sl {
    int x, y, z, xx, yy, zz;
} a[N];
struct sa {
    int next, id;
} e[4 * N];
int head[4 * N], i, j, n, m, k, l, sum, col[4 * N], tot;
map<int, int> Hash;
bool flag;
int get(int x, int y, int z) { return x * 1000000 + y * 1000 + z; }
void add(int x, int y) {
    e[++sum].next = head[x];
    e[sum].id = y;
    head[x] = sum;
}
void dfs(int x, int fa) {
    if (!flag)
        return;
    col[x] = col[fa] + 1;
    for (int i = head[x]; i != -1; i = e[i].next) {
        int v = e[i].id;
        if (v == fa)
            continue;
        if (!col[v])
            dfs(v, x);
        else {
            if (col[v] != col[x] + 1) {
                flag = false;
                return;
            } else
                continue;
        }
    }
}
int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d%d", &a[i].x, &a[i].y, &a[i].z, &a[i].xx, &a[i].yy,
              &a[i].zz);
        int x = get(a[i].x, a[i].y, a[i].z);
        int y = get(a[i].xx, a[i].yy, a[i].zz);
        if (!Hash[x])
            Hash[x] = ++tot, x = tot;
        else
            x = Hash[x];
        if (!Hash[y])
            Hash[y] = ++tot, y = tot;
        else
            y = Hash[y];
        if (x != y) {
            add(x, y);
            add(y, x);
        }
    }
    flag = true;
    for (i = 1; i <= tot; i++) {
        if (!col[i])
            dfs(i, 0);
        if (!flag)
            break;
    }
    if (flag)
        printf("No true closed chains\n");
    else
        printf("True closed chains\n");
    memset(head, -1, sizeof(head));
    Hash.clear();
    memset(col, 0, sizeof(col));
    sum = 0;
    tot = 0;
    for (i = 1; i <= n; i++) {
        int x = get(0, a[i].x, a[i].y);
        int y = get(0, a[i].xx, a[i].yy);
        if (!Hash[x])
            Hash[x] = ++tot, x = tot;
        else
            x = Hash[x];
        if (!Hash[y])
            Hash[y] = ++tot, y = tot;
        else
            y = Hash[y];
        if (x != y) {
            add(x, y);
            add(y, x);
        }
    }
    flag = true;
    for (i = 1; i <= tot; i++) {
        if (!col[i])
            dfs(i, 0);
        if (!flag)
            break;
    }
    if (flag)
        printf("No floor closed chains\n");
    else
        printf("Floor closed chains\n");
}