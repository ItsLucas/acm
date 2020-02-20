#include <bits/stdc++.h>

using namespace std;

set<long long> x, y;

int main() {
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        long long a, b;
        cin >> a >> b;
        x.insert(a);
        y.insert(b);
        long long cnt = (long long)y.size() * n + (long long)x.size() * n -
                        (long long)x.size() * (long long)y.size();
        cout << n * n - cnt << " ";
    }
    cout << endl;
    return 0;
}