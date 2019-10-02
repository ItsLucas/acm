#include <bits/stdc++.h>

using namespace std;

int a[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxi = 0;
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > maxx) {
            maxi = i;
            maxx = a[i];
        }
    }
    if (maxi == 1)
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}