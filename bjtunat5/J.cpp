#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5;
long long a[maxn + 5], sum[maxn * 4 + 5], tag[maxn * 4 + 5];
int N;
inline void op(long long k) { sum[k] = sum[k * 2] + sum[k * 2 + 1]; }

void build(long long l, long long r, long long k) {
    if (l > r)
        return;
    if (l == r) {
        sum[k] = a[l];
        tag[k] = 0;
        return;
    }
    long long mid = (l + r) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    op(k);
}

void pushdown(long long lenl, long long lenr, long long k) {
    if (tag[k]) {
        tag[k * 2] = tag[k];
        tag[k * 2 + 1] = tag[k];
        sum[k * 2] = tag[k] * lenl;
        sum[k * 2 + 1] = tag[k] * lenr;
        tag[k] = 0;
    }
}

void change(long long l, long long r, long long pl, long long pr, long long k,
            long long val) {
    if (l > r || pl > r || pr < l)
        return;
    if (l >= pl && r <= pr) {
        sum[k] = val * (r - l + 1);
        tag[k] = val;
        return;
    }

    long long mid = (l + r) / 2;
    pushdown(mid - l + 1, r - mid, k);
    change(l, mid, pl, pr, k * 2, val);
    change(mid + 1, r, pl, pr, k * 2 + 1, val);
    op(k);
}

long long query(long long l, long long r, long long ql, long long qr,
                long long k) {
    if (l > r || ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return sum[k];
    long long mid = (l + r) / 2, ans = 0;
    pushdown(mid - l + 1, r - mid, k);
    if (mid >= l)
        ans += query(l, mid, ql, qr, k * 2);
    if (mid < r)
        ans += query(mid + 1, r, ql, qr, k * 2 + 1);
    return ans;
}

long long qu(int l, int r) { return query(1, N, l, r, 1); }

void mo(int l, int r, int val) { change(1, N, l, r, 1, val); }

int main() {
    cin >> N;
    int n = N;
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, N, 1);
    int a, b, s, op;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            cout << qu(a, b) << endl;
        } else {
            cin >> a >> b >> s;
            mo(a, b, -s);
        }
    }
    return 0;
}