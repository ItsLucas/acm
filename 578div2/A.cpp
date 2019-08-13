#include <bits/stdc++.h>

using namespace std;

bool room[10];

void assignL() {
    int i;
    for (i = 0; i < 10; i++) {
        if (room[i] == 0)
            break;
    }
    room[i] = true;
}

void assignR() {
    int i;
    for (i = 9; i >= 0; i--) {
        if (room[i] == 0)
            break;
    }
    room[i] = true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        switch (c) {
        case 'L':
            assignL();
            break;
        case 'R':
            assignR();
            break;
        default: {
            int pos = c - '0';
            room[pos] = false;
        }
        }
    }
    for (int i = 0; i <= 9; i++) {
        cout << room[i];
    }
    cout << endl;
    return 0;
}