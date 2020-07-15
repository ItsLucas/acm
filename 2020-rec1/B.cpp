#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n / 500;
    int re = n - a * 500;
    int b = re / 5;
    cout << a * 1000 + b * 5 << endl;
    return 0;
}