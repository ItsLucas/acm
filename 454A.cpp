#include <bits/stdc++.h>

using namespace std;

char m[110][110];
int cur = 0;

void draw(int x, int y, char c) {
    cur++;
    m[x][y] = c;
}

int main() {
    int n;
    cin >> n;
    int mid = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            m[i][j] = '*';
        }
    }
    for (int i = 1; i <= mid; i++) {
        cur = 1;
        for (int l = mid, r = mid; l >= 1, r <= n; l--, r++) {
            if (l == mid && r == mid) {
                m[i][l] = 'D';
            } else if (cur < 2 * i - 1) {
                draw(i, l, 'D');
                draw(i, r, 'D');
            }
        }
    }
    for (int i = 1; i <= mid; i++) {
        for (int j = 1; j <= n; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
    for (int i = mid - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
    return 0;
}