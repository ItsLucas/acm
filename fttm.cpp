#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        map<int, int> mp;
        int a;
        int maxx = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            mp[a]++;
            maxx = max(mp[a], maxx);
        }
        printf("%d\n", maxx);
    }
    return 0;
}