#include <bits/stdc++.h>

using namespace std;

int sum(int n) {
    int ans = 0;
    for (n; n > 0; n /= 10) {
        ans += n % 10;
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    int n = 0;
    while (k) {
        n++;
        if (sum(n) == 10)
            k--;
    }
    cout << n << endl;
}