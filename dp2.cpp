#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int w[1001];
int n,m;

int main() {
    while(1) {
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;i++) {
            cin>>w[i];
        }
        cin>>m;
        sort(w+1,w+n+1);
        int top = w[n];
        if(m < 5) {
            cout<<m<<endl;
            continue;
        }
        m -= 5;
        for(int i=1;i<=n-1;i++) {
            for(int j=0;j<=m;j++) {
                if(w[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
            }
        }
        cout<<m+5-dp[n-1][m]-top<<endl;
    }
    return 0;
}