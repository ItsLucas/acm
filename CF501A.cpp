#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double mi = max(3 * a / 10, a - a * c / 250);
    double va = max(3 * b / 10, b - b * d / 250);
    // cout << mi << " " << va << endl;
    if (mi > va) {
        cout << "Misha" << endl;
    } else if (mi == va) {
        cout << "Tie" << endl;
    } else {
        cout << "Vasya" << endl;
    }
    return 0;
}