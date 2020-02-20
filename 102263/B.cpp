#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        int t = n - k;
        if (t == 0 || t == 1) {
            if (n % 2)
                cout << "Kilani" << endl;
            else
                cout << "Ayoub" << endl;
        } else
            cout << "Kilani" << endl;
    }
    return 0;
}