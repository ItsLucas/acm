#include <bits/stdc++.h>

using namespace std;
int board[10] = {0};
int cnt = 0;
bool check(int k) {
    for (int i = 1; i < k; i++) {
        if (board[i] == board[k] || abs(board[i] - board[k]) == abs(i - k))
            return false;
    }
    return true;
}
int f(int n) {
    int k = 1;
    board[1] = 0;
    while (k > 0) {
        board[k]++;
        while (board[k] <= n && !check(k))
            board[k]++;
        if (board[k] <= n) {
            if (k == n) {
                cnt++;
                cout << "-------------" << cnt << "-------------" << endl;
                for (int i = 1; i <= n; i++)
                    cout << i << "--->" << board[i] << endl;
            } else {
                k++;
                board[k] = 0;
            }
        } else
            k--;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int cnt = f(n);
    cout << "Total solution count for " << n << " queens: " << cnt << endl;
    return 0;
}