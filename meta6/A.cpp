#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int cnt = 0;
        int x;
        for (int i = 1; i <= 4; i++) {
            cin >> x;
            if (x != 0)
                cnt++;
        }
        switch (cnt) {
        case 0:
            cout << "Typically Otaku" << endl;
            break;
        case 1:
            cout << "Eye-opener" << endl;
            break;
        case 2:
            cout << "Young Traveller" << endl;
            break;
        case 3:
            cout << "Excellent Traveller" << endl;
            break;
        case 4:
            cout << "Contemporary Xu Xiake" << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}