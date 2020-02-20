#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m, k;
int e[1000500];

void readin() {
    scanf("%d %d", &n, &k);
    m = 2 * n * k;
    for (int i = 0; i < m; i++)
        scanf("%d", &e[i]);
    sort(e, e + m);
}

bool check(int delta) {
    int cnt = 0;
    for (int i = m - 1; i > 0; i--)
        if (e[i] - e[i - 1] <= delta)
            if (m - i + 1 >= 2 * (cnt + 1) * k) {
                cnt++;
                i--;
                if (cnt == n)
                    return true;
            }
    return false;
}

void work() {
    int l = 0, r = 1000000001;
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d", r + 1);
}

int main() {
    readin();
    work();
    return 0;
}