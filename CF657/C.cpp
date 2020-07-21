#include <bits/stdc++.h>

using namespace std;

struct flower {
    int val;
    int id;
    bool type;
    bool operator<(const flower &f) const { return val < f.val; }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        priority_queue<flower, vector<flower>, less<flower>> q;
        vector<int> pb(100010);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            q.push({a, i, false});
            pb[i] = b;
        }
        long long tot = 0;
        while (n > 0) {
            flower f = q.top();
            q.pop();
            if (!f.type) {
                n--;
                tot += f.val;
                q.push({pb[f.id], f.id, true});
            } else {
                n = 0;
                tot += f.val * (long long)n;
            }
        }
        cout << tot << endl;
    }
    return 0;
}