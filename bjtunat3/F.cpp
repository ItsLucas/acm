#include <bits/stdc++.h>

using namespace std;

char mat[4][4];

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> mat[i][j];
            }
        }
        cout << (!(mat[1][1] == 'U' || mat[1][3] == 'U' || mat[3][1] == 'U' ||
                   mat[3][3] != 'T')
                     ? "definable"
                     : "undefinable")
             << endl;
    }
    return 0;
}