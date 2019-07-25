#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;

int dp[maxn][maxn];
int a[maxn][maxn];
int n;

int main() {
    int c;
    cin>>c;
    while(c-->0) {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                cin>>a[i][j];
            }
        }
        for(int i=n;i>=1;i--) {
            for(int j=1;j<=i;j++) {
                dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
            }
        }
        cout<<dp[1][1]<<endl;
    }
    return 0;
}