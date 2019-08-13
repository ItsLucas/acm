#include <bits/stdc++.h>

using namespace std;

char win[256];

char seqa[110], seqb[110];

int main() {
    int n;
    cin >> n;
    win['R'] = 'P';
    win['S'] = 'R';
    win['P'] = 'S';
    scanf("%s", seqa);
    scanf("%s", seqb);
    for (int i = 0; i < strlen(seqa); i++) {
        if (seqa[i] == seqb[i]) {
            cout << win[seqa[i]];
        } else {
            if (win[seqa[i]] == win[win[seqb[i]]]) {
                cout << win[seqb[i]];
            } else {
                cout << win[seqa[i]];
            }
        }
    }
    cout << endl;
    return 0;
}