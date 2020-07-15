#include <bits/stdc++.h>

using namespace std;

map<int, long long> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        mp[i - b] += b;
    }
    long long maxx = 0;
    for (auto i : mp) {
        maxx = max(i.second, maxx);
    }
    cout << maxx << endl;
    return 0;
}