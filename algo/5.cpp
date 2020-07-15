#include <bits/stdc++.h>

int a[10][10];
using namespace std;
bool find(int n, int val) {
    int i = n, j = n;
    while (i >= 0 && j >= 0) {
        if (a[i][j] > val) {
            i--;
        } else if (a[i][j] < val) {
            j--;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;
    cout << find(n, k) << endl;
    return 0;
}