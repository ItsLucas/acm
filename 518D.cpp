#include <bits/stdc++.h>

using namespace std;

double f[2001][2001];

int main() {
    int n,t;
    double p;
    cin>>n>>p>>t;
    f[1][1]=p;
	f[0][1]=1-p;
	f[0][0]=1;
	for (int j=1;j<=t;j++){
		for (int i=0;i<=n;i++){
			if (!i){
				f[i][j]=f[i][j-1]*(1-p);
			}
			else if (i==n){
				f[i][j]=f[i][j-1]+f[i-1][j-1]*p;
			}
			else {
				f[i][j]=f[i][j-1]*(1-p)+f[i-1][j-1]*p;
			}
		}
	}
    double ans = 0;
	for (int i=1;i<=n;i++){
		ans+=f[i][(int)t]*i;
	}
    cout<<setprecision(15)<<ans<<endl;
    return 0;
}