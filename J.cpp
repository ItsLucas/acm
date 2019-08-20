#include <bits/stdc++.h>

using namespace std;

char c[100050];
int g[100050];

vector<int> getf(int x) {
    vector<int> v;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (x / i != i)
                v.push_back(x / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    scanf("%s", c);
    int n = strlen(c);
    bool flag1 = true;
    for (int i = 0; i < n; i++) {
        if (c[i] == 'P') {
            flag1 = false;
            break;
        }
    }
    if (flag1) {
        cout << n - 1 << endl;
        return 0;
    }
    vector<int> v;
    v = getf(n);
    for (int i = 2; i < n; i++) {
        g[__gcd(i, n)]++;
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        bool flag = false;
        for (int j = 0; j < v[i]; j++) {
            bool ok = 1;
            for (int k = j; k < n; k += v[i]) {
                if (c[k] == 'P') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                flag = 1;
            }
        }
        if (flag) {
            cnt += g[v[i]];
        }
    }
    cout << cnt << endl;
    return 0;
}