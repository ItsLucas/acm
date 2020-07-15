#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

vector<pair<int, int>> ans[9];
int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            v.push_back(make_pair(i, j));
        }
    }
    for (auto i : v) {
        for (auto j : v) {
            if (i.first + j.second == i.second + j.first) {
                ans[i.first + j.second].push_back(i);
                ans[i.first + j.second].push_back(j);
            }
        }
    }
    for (auto i : ans) {
        unique(i.begin(), i.end());
    }
    for (auto i : ans) {
        for (auto j : i) {
            cout << "(" << j.first << " " << j.second << ") ";
        }
        cout << endl;
    }
    return 0;
}