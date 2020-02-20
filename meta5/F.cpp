#include <bits/stdc++.h>

using namespace std;

bool avl[7][256];

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        for (int i = 0; i <= 6; i++) {
            for (int j = 0; j <= 255; j++) {
                avl[i][j] = false;
            }
        }
        for (int i = 1; i <= 6; i++) {
            string banner;
            cin >> banner;
            for (int j = 0; j < banner.size(); j++) {
                // cout << banner[j] << endl;
                avl[i][banner[j]] = true;
            }
        }
        vector<char> v;
        v.push_back('a');
        v.push_back('b');
        v.push_back('h');
        v.push_back('i');
        v.push_back('n');
        v.push_back('r');
        bool flag = false;
        do {
            if (avl[1][v[0]] && avl[2][v[1]] && avl[3][v[2]] && avl[4][v[3]] &&
                avl[5][v[4]] && avl[6][v[5]]) {
                flag = true;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}