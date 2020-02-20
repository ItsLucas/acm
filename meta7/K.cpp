#include <bits/stdc++.h>

using namespace std;

char dict[4] = {'L', 'R', 'U', 'D'};
int main() {
    int n, m;
    cin >> n >> m;
    string str;
    srand(time(0));
    for (int i = 1; i <= n; i++) {
        cin >> str;
    }
    for (int i = 1; i <= 20; i++) {
        cout << 'L';
    }
    for (int i = 1; i <= 20; i++) {
        cout << 'U';
    }
    for (int i = 1; i <= 20; i++) {
        cout << 'R';
    }
    for (int i = 1; i <= 20; i++) {
        cout << 'D';
    }
    for (int i = 1; i <= 49920; i++) {
        int x = rand() % 4;
        cout << dict[x];
    }
    cout << endl;
    return 0;
}