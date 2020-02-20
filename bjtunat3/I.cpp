#include <bits/stdc++.h>

#define len b - a + 1
using namespace std;

map<int, int> ma;

int main() {
    int n;
    cin >> n;
    ma[-1] = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        auto it = ma.lower_bound(a);
        int ans = (--it)->second + len;
        if (ma.count(b)) {
            if (ma[b] < ans)
                ma[b] = ans;
        } else {
            auto ii = ma.lower_bound(b);
            ii--;
            if (ii->second < ans)
                ma[b] = ii->second + len;
        }
        auto j = ma.upper_bound(b);
        while (j != ma.end() && j->second <= ans) {
            j++;
        }
        ma.erase(ma.upper_bound(b), j);
    }
    auto i = ma.end();
    cout << (--i)->second << endl;
    return 0;
}