#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, num, odd, eve, prezero;
char s[maxn];
long long tot[maxn], ans;
int main() {
    int t;
    bool flag;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        num = 0, odd = 0, eve = 0, ans = 0, prezero = 0;
        flag = 1;

        for (int i = 0; i < n; i++) {
            tot[i] = 0;
            if (s[i] == '0') {

                if (s[i - 1] == '0' && i > 0) {
                    tot[i] = tot[i - 1];
                } else {
                    tot[i] += (num - 1) / 2;
                    if (flag)
                        tot[i] += eve;
                    else {
                        tot[i] += odd;
                        // cout << "^\n" << odd << " " << i << "\n";
                    }
                }
                ans += tot[i];
                if (flag)
                    odd++;
                else
                    eve++;
                prezero++;
            } else {
                tot[i] += num / 2;
                if (flag)
                    tot[i] += odd;
                else
                    tot[i] += eve;
                tot[i] -= prezero;
                ans += tot[i];
                flag ^= 1;
                num++;
                prezero = 0;
            }
            // cout << tot[i] << "  ";
        }
        printf("%lld\n", ans);
    }
}