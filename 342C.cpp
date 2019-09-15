#include <bits/stdc++.h>

using namespace std;

double r, h;
int ans;

int main() {
    scanf("%lf%lf", &r, &h);
    int tmp = int(h / r);
    ans = tmp * 2;
    h -= tmp * r;
    if (h >= (r / 2.0f)) {
        ans += 2, h -= r;
    }
    h += r + (2.0f - sqrt(3.0f)) * r / 2.0f;
    if (h >= r) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}