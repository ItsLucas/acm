#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
bool vis[MAXN];
int prime[MAXN];
bool used[MAXN];
vector<pair<int, int>> v;
vector<int> a, a2;

void get_prime() {
    int tot = 0;
    for (int i = 2; i < MAXN - 5; i++) {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++) {
            int d = i * prime[j];
            if (d >= MAXN - 5)
                break;
            vis[d] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    get_prime();
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; prime[i] <= n / 2; i++) {
        a.clear();
        a.push_back(prime[i]);
        for (int j = 3 * prime[i]; j <= n; j += prime[i]) {
            if (!used[j])
                a.push_back(j);
        }
        if (a.size() % 2 == 0) {
            a2.push_back(2 * prime[i]);
        } else {
            a.push_back(2 * prime[i]);
        }
        for (int j = 0; j + 1 < a.size(); j += 2) {
            v.push_back(make_pair(a[j], a[j + 1]));
            used[a[j]] = 1;
            used[a[j + 1]] = 1;
        }
    }
    if (n >= 2) {
        a2.push_back(2);
    }
    if (n >= 4) {
        a2.push_back(4);
    }
    for (int i = 4; i + i <= n; i++) {
        if (!used[i + i] && vis[i]) {
            a2.push_back(i + i);
        }
    }
    int maxi = a2.size();
    for (int i = 0; i <= 10; i++) {
        for (int i = 0; i + 1 < maxi; i += 2) {
            v.push_back(make_pair(a2[i], a2[i + 1]));
        }
        cout << v.size() << endl;
        for (auto i : v) {
            cout << i.first << " " << i.second << endl;
        }
        return 0;
    }
}