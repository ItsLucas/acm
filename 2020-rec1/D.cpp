#include <bits/stdc++.h>

using namespace std;

int x, y;
int a[2005];

inline int min3(int num1, int num2, int num3) {
    int minn = (num1 < num2) ? num1 : num2;
    minn = (minn < num3) ? minn : num3;
    return minn;
}

int dis(int i, int j) {
    int v1 = abs(j - i);
    int v2 = abs(x - i) + 1 + abs(j - y);
    int v3 = abs(y - i) + 1 + abs(j - x);
    return min3(v1, v2, v3);
}

int main() {
    int n;
    cin >> n >> x >> y;
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i < j; i++) {
            a[dis(i, j)]++;
        }
    }
    for (int k = 1; k <= n - 1; k++) {
        cout << a[k] << endl;
    }
    return 0;
}