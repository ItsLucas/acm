#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a, b, c;

int main() {
    cin >> a >> b;
    c = (a / b) * (a - b) + ((a / b) - 1) * b;
    a % b ? c += (1 + a / b) * (a % b) : c += 0;
    cout << c << endl;
    return 0;
}