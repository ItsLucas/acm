#include <bits/stdc++.h>

using namespace std;

static constexpr int mask = (1 << 22) - 1;
int a[12345678], b[mask];

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        b[mask ^ a[i]] = a[i];
    }
    for (int i = mask; i >= 0; i--) {
        if (!b[i]) {
            for (int j = 0; j < 22; j++) {
                if (b[i | (1 << j)]) {
                    b[i] = b[i | (1 << j)];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (b[a[i]]) {
            printf("%d ", b[a[i]]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
    return 0;
}
