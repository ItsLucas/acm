#include <bits/stdc++.h>

using namespace std;

struct mark {
    int a;
    bool used = false;
};
bool sq(int x) {
    int a = floor(sqrt(x));
    return a * a == x;
}
int a[200010];
vector<mark> cc1, cc2;
int main() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (sq(a[i])) {
            cc1.push_back({a[i], false});
            c1++;
        } else {
            cc2.push_back({a[i], false});
            c2++;
        }
    }
    if (c1 == c2) {
        cout << 0 << endl;
        return 0;
    } else if (c1 > c2) {
        int op = 0;
        int cnt = (c1 - c2) / 2;
        for (mark i : cc1) {
            if (cnt == 0)
                break;
            if (i.a != 0 && (!sq(i.a + 1))) {
                op++;
                i.used = true;
                cnt--;
            }
        }
        for (mark i : cc1) {
            if (cnt == 0)
                break;
            if (i.a == 0 && (!sq(i.a + 2)) && !i.used) {
                op += 2;
                i.used = true;
                cnt--;
            }
        }
        cout << op << endl;
    } else {
        long long op = 0;
        int cnt = (c2 - c1) / 2;
        vector<int> v;
        for (mark i : cc2) {
            int x = sqrt(i.a);
            v.push_back(min(i.a - x * x, (x + 1) * (x + 1) - i.a));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < cnt; i++) {
            op += v[i];
        }
        cout << op << endl;
    }
    return 0;
}