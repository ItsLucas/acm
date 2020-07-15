#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        priority_queue<int, vector<int>, less<int>> q;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}