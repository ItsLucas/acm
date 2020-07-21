#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        !((n - i) % i) ? cnt++ : cnt = cnt;
    }
    cout << cnt << endl;
    return 0;
}