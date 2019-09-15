#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w[100010];
char dict[5] = {'w', 'r', 'o', 'n', 'g'};
int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int a[5];
    int ans = 0;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (a[j] == 0 && s[i] == dict[j]) {
                bool flag = false;
                for (int k = 0; k < j; k++) {
                    if (a[k] == 0)
                        flag = true;
                }
                if (!flag)
                    a[j] = w[i];
            }
        }
        if (a[4] != 0) {
            int minn = 2147483621;
            for (int j = 0; j < 5; j++) {
                minn = min(a[j], minn);
            }
            ans += minn;
            memset(a, 0, sizeof(a));
        }
    }
    cout << ans << endl;
    return 0;
}