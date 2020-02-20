#include <bits/stdc++.h>

using namespace std;

int a[101], b[101];

set<int> aa, bb;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        aa.insert(a[i]);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        bb.insert(b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = a[i], y = b[j];
            if (aa.find(x + y) == aa.end() && bb.find(x + y) == bb.end()) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }
    return 0;
}