#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1e5 + 10;

struct node {
    int id;
    int v;
    node(int id = 0, int v = 0) : id(id), v(v){};
    inline bool operator<(const node &a) const { return v < a.v; }
} k[maxn];

bool use[maxn];

int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        memset(use, false, sizeof(use));
        for (int i = 1; i <= n; i++) {
            cin >> k[i].v;
            k[i].id = i;
        }
        sort(k + 1, k + n + 1);
        int now = 1, need1 = 1, need2 = 1;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            while (need1 + need2 <= n - i + 1 && now < k[i].v) {
                need1 *= 2, need2 *= 2, now++;
            }
            if (need1 + need2 > n - i + 1) {
                flag = true;
                break;
            }
            need1 ? need1--, use[k[i].id] = true : need2--;
            if (!need1 && !need2) {
                break;
            }
        }
        if (flag || need1 || need2) {
            cout << "Case " << c << ": NO" << endl;
        } else {
            cout << "Case " << c << ": YES" << endl;
            for (int i = 1; i <= n; i++) {
                cout << use[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}