#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << ((n - 1 - a) / (b - a) * 2) + 1 << endl;
    return 0;
}