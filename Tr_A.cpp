#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M_SZ = 10;

using Mat = array<array<ll, M_SZ>, M_SZ>;

#define rep2                                                                   \
    for (int i = 0; i < M_SZ; i++)                                             \
        for (int j = 0; j < M_SZ; j++)

void zero(Mat &a) { rep2 a[i][j] = 0; }
void one(Mat &a) { rep2 a[i][j] = (i == j); }

Mat mul(const Mat &a, const Mat &b, ll p) {
    Mat ans;
    zero(ans);
    rep2 if (a[i][j]) for (int k = 0; k < M_SZ; k++) {
        (ans[i][k] += a[i][j] * b[j][k]) %= p;
    }
    return ans;
}

Mat qk(Mat a, ll b, ll p) {
    Mat ans;
    one(ans);
    for (; b; b >>= 1) {
        if (b & 1)
            ans = mul(a, ans, p);
        a = mul(a, a, p);
    }
    return ans;
}

Mat mat;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, tmp;
        ll k;
        cin >> n >> k;
        int a = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        mat = qk(mat, k, 9973);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + mat[i][i]) % 9973;
        }
        cout << ans << endl;
    }
    return 0;
}