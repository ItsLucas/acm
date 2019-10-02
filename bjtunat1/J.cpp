#include <bits/stdc++.h>
using namespace std;
struct sa {
    int x, y;
};
struct sl {
    sa a[10];
    bool pd;
    int sum;
} t[20];
int i, j, n, m, k, l, o, p, last, x, ans, minn;
char c;
bool cmp1(sa x, sa y) { return (x.y < y.y || (x.y == y.y && x.x < y.x)); }
void add(int x, int num) {
    bool flag = false;
    for (int i = 1; i <= t[x].sum; i++)
        if (num == t[x].a[i].x) {
            t[x].a[i].y++;
            flag = true;
            break;
        }
    if (!flag)
        t[x].a[++t[x].sum].x = num, t[x].a[t[x].sum].y = 1;
}
int Delete(int x) {
    std::sort(t[x].a + 1, t[x].a + t[x].sum + 1, cmp1);
    int ans = t[x].a[1].x;
    if (t[x].a[1].y > 1)
        t[x].a[1].y--;
    else {
        for (int i = 1; i < t[x].sum; i++)
            t[x].a[i].x = t[x].a[i + 1].x, t[x].a[i].y = t[x].a[i + 1].y;
        t[x].sum--;
    }
    return ans;
}
bool check(int x) {
    if (t[x].sum == 1 && !t[x].pd)
        return true;
    else
        return false;
}
int main() {
    scanf("%d%d\n", &n, &k);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 4; j++) {
            scanf("%c", &c);
            int x;
            if (c == 'A')
                x = 1;
            if (c == 'D')
                x = 10;
            if (c == 'J')
                x = 12;
            if (c == 'Q')
                x = 11;
            if (c == 'K')
                x = 13;
            if (c >= '2' && c <= '9')
                x = c - '0';
            add(i, x);
        }
        scanf("\n");
    }
    minn = 14;
    ans = 0;
    t[k].pd = true;
    for (i = 1; i <= n; i++)
        if (t[i].sum == 1 && !t[i].pd) {
            if (t[i].a[1].x < minn)
                minn = t[i].a[1].x, ans = i;
        }
    if (ans != 0) {
        printf("%d", ans);
        return 0;
    }
    l = k;
    last = 14;
    while (1) {
        if (last == 14) {
            x = Delete(l);
            last = x;
            if (check(l)) {
                printf("%d", l);
                return 0;
            }
            l++;
            if (l > n)
                l -= n;
            add(l, x);
        } else {
            if (t[l].pd) {
                t[l].pd = false;
                last = 14;
                if (check(l)) {
                    printf("%d", l);
                    return 0;
                }
                l++;
                if (l > n)
                    l -= n;
                t[l].pd = true;
            } else {
                x = Delete(l);
                last = x;
                if (check(l)) {
                    printf("%d", l);
                    return 0;
                }
                l++;
                if (l > n)
                    l -= n;
                add(l, x);
            }
        }
    }
}