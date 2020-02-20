#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct plane {
    int id;
    ll cost;
    plane(int id = 0, ll cost = 0) : id(id), cost(cost){};
    bool operator<(const plane &p) const { return cost < p.cost; }
};

plane p[600010];

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<plane> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].cost;
        p[i].id = i;
    }
    ll ans = 0;
    int i = 1;
    for (i = 1; i <= k; i++) {
        q.push(p[i]);
    }
    for (i; i <= n + k; i++) {
        if (i <= n) {
            q.push(p[i]);
        }
        plane x = q.top();
        q.pop();
        p[x.id].id = i;
        ans += (i - x.id) * x.cost;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << p[i].id << " ";
    }
    cout << endl;
    return 0;
}