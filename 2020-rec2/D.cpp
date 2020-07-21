#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e7 + 5;
// Thank you qdd

bool vis[MAXN];
int prime[MAXN];
int a[500050], x[500050], y[500050];
void get_prime() {
    int tot = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++) {
            int d = i * prime[j];
            if (d >= MAXN)
                break;
            vis[d] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

vector<int> getf(int x) {
    vector<int> v;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        v.push_back(x);
    return v;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    get_prime();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        vector<int> l = getf(a[i]);
        if (l.size() <= 1) {
            x[i] = y[i] = -1;
        } else {
            x[i] = l[0];
            int tmp = l[1];
            for (int j = 2; j < l.size(); j++) {
                tmp = tmp * l[j];
            }
            y[i] = tmp;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << y[i] << " ";
    }
    cout << endl;
    return 0;
}