#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<int>> a, b, c, d;

int main() {
    int x, y, A, B, C;
    cin >> x >> y >> A >> B >> C;
    int t;
    for (int i = 1; i <= A; i++) {
        cin >> t;
        a.push(t);
    }
    for (int i = 1; i <= B; i++) {
        cin >> t;
        b.push(t);
    }
    for (int i = 1; i <= C; i++) {
        cin >> t;
        c.push(t);
    }
    for (int i = 1; i <= x; i++) {
        c.push(a.top());
        a.pop();
    }
    for (int i = 1; i <= y; i++) {
        c.push(b.top());
        b.pop();
    }
    long long ans = 0;

    for (int i = 1; i <= x + y; i++) {
        ans += (long long)c.top();
        c.pop();
    }
    cout << ans << endl;
    return 0;
}