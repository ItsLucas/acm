#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int a, b;
        cin >> a >> b;
        if (b > a) {
            cout << "WeWillEatYou" << endl;
        } else {
            cout << "FunkyMonkeys" << endl;
        }
    }
    return 0;
}