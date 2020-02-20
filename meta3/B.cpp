#include <bits/stdc++.h>

using namespace std;

bool upp[1010];
char upc[1010], downc[1010];
int main() {
    string up, down;
    cin >> up;
    cin >> down;
    int ups = 0, upd = 0;
    int n = up.size();
    for (int i = 0; i < up.size(); i++) {
        up[i] == '#' ? ups++, upp[i] = 1 : upd++;
    }
    int ds = 0, dd = 0;
    int poss = 23333;
    int both = 0;
    for (int i = 0; i < down.size(); i++) {
        down[i] == '#' ? ds++ : dd++;
        if (down[i] == '#' && up[i] == '#')
            poss = i, both++;
    }
    if (ds == 0 && ups != 0) {
        cout << "YES" << endl;
        for (int i = 1; i <= ups; i++) {
            cout << "#";
        }
        for (int i = 1; i <= upd; i++) {
            cout << ".";
        }
        cout << endl;
        for (int i = 1; i <= dd; i++) {
            cout << ".";
        }
        cout << endl;
        return 0;
    }
    if (ups == 0 && ds != 0) {
        cout << "YES" << endl;
        for (int i = 1; i <= upd; i++) {
            cout << ".";
        }
        cout << endl;
        for (int i = 1; i <= ds; i++) {
            cout << "#";
        }
        for (int i = 1; i <= dd; i++) {
            cout << ".";
        }
        cout << endl;

        return 0;
    }
    if (poss == 23333) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int pos = 0;
    for (int i = 1; i <= ups - both; i++) {
        upc[pos] = '#';
        downc[pos] = '.';
        pos++;
    }
    for (int i = 1; i <= both; i++) {
        upc[pos] = '#';
        downc[pos] = '#';
        ds--;
        pos++;
    }
    for (int i = 1; i <= ds; i++) {
        upc[pos] = '.';
        downc[pos] = '#';
        pos++;
    }
    for (int i = pos; i < n; i++) {
        upc[i] = '.';
        downc[i] = '.';
    }
    cout << upc << endl << downc << endl;
    return 0;
}