#include <bits/stdc++.h>
using namespace std;
const int maxn = 101010;
typedef long long ll;
struct dat {
    int id, p, v;
} a[maxn];
bool operator<(dat a, dat b) {
    if (a.p != b.p)
        return a.p > b.p;
    else if (a.v != b.v)
        return a.v > b.v;
    return a.id > b.id;
}

int n;
ll sum, num, ls, ln;
vector<int> v;
void solve() {
    cin >> n;
    sum = num = 0;
    v.clear();

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].p >> a[i].v;
        sum += 1ll * a[i].v * a[i].p;
        num += 1ll * a[i].v;
        a[i].id = i;
    }
    ls = sum, ln = num;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        ++num;
        sum += a[i].p;
        if (num * ls < sum * ln) {
            v.push_back(a[i].id);
            ls = sum;
            ln = num;
        } else {
            --num;
            sum -= a[i].p;
            break;
        }
    }
    ll g = __gcd(num, sum);
    cout << sum / g << "/" << num / g << endl;
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}