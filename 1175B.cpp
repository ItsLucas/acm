#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct oo_t {
    inline ll operator+() { return 1LL << 32; }
    inline ll operator-() { return -(1LL << 32); }
} oo;

int main() {
    int n;
    cin >> n;
    stack<ll> gcc;
    gcc.push(1);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        if (t == "for") {
            int x;
            cin >> x;
            gcc.push(min(+oo, gcc.top() * x));
        } else if (t == "end") {
            gcc.pop();
        } else {
            res += gcc.top();
        }
    }

    if (res >= +oo)
        cout << "OVERFLOW!!!" << endl;
    else
        cout << res << endl;
}
