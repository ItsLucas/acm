#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static constexpr ll maxn = 100001;
ll s[100010];
long long f(long long x) { return lower_bound(s + 1, s + 100001, x) - s; }
void init() {
    for (ll i = 1; i < maxn; i++) {
        s[i] = s[i - 1] + i * 1LL;
    }
}
int main() {
    init();
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        ll ha, hb, ta, tb;
        cin >> ha >> hb >> ta >> tb;
        ll fi = f(ha + hb);
        string str;
        string str1;
        ll pos = f(ha);
        ll hitb = s[pos] - ha;
        ll s1 = 1LL * pos * ta + 1LL * fi * tb;
        if (s[fi] - s[pos] >= hb) {
            for (ll i = 1; i <= pos; i++) {
                str += 'A';
            }
        } else {
            for (ll i = 1; i <= pos; i++) {
                if (i != hitb)
                    str += 'A';
                else
                    str += 'B';
            }
        }
        for (ll i = pos + 1; i <= fi; i++)
            str += 'B';
        pos = f(hb);
        ll s2 = 1LL * fi * ta + 1LL * pos * tb;
        ll locb = s[pos] - hb;
        ll hitbb = upper_bound(s + 1, s + maxn, locb) - s - 1;
        ll ch = s[fi] - s[pos];
        if (ch + s[hitbb] >= ha) {
            for (ll i = 1; i <= hitbb; i++) {
                str1 += 'A';
            }
            for (ll i = hitbb + 1; i <= pos; i++) {
                str1 += 'B';
            }
            for (ll i = pos + 1; i <= fi; i++) {
                str1 += 'A';
            }
        } else {
            ll l = ha - ch;
            for (ll i = 1; i <= pos; i++) {
                if (l - i > i || l == i) {
                    l -= i;
                    str1 += 'A';
                } else {
                    str1 += 'B';
                }
            }
            for (ll i = pos + 1; i <= fi; i++) {
                str1 += 'A';
            }
        }
        if (s1 > s2) {
            cout << s2 << " ";
            cout << str1 << endl;
        } else if (s1 < s2) {
            cout << s1 << " ";
            cout << str << endl;
        } else if (str < str1) {
            cout << s1 << " ";
            cout << str << endl;
        } else {
            cout << s2 << " ";
            cout << str1 << endl;
        }
    }
    return 0;
}
