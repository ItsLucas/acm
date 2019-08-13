#include <bits/stdc++.h>

using namespace std;

int n;
int mat[2001][2001];
int ss[2001][2001];

int matsum(int k) {
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += mat[i][j];
        ss[0][j] = sum;

        for (int i = 1; i < n - k + 1; i++) {
            sum += (mat[i + k - 1][j] - mat[i - 1][j]);
            ss[i][j] = sum;
        }
    }
    int maxsum = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += ss[i][j];
        maxsum = max(sum, maxsum);
        for (int j = 1; j < n - k + 1; j++) {
            sum += (ss[i][j + k - 1] - ss[i][j - 1]);
            maxsum = max(sum, maxsum);
        }
    }
    return maxsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            c == 'B' ? mat[i][j] = 1 : mat[i][j] = 0;
        }
    }
    cout << matsum(k) << endl;
    return 0;
}