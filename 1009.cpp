#include<bits/stdc++.h> 
using namespace std; 

typedef unsigned long long ull;
typedef long long ll;

#define p 101 
#define MOD 1000000007 
char str[300010];
struct Query { 
	int L, R; 
    Query(int L = 0,int R = 0):L(L),R(R){};
}; 

bool isp(int L, int R) { 
	while (R > L) 
		if (str[L++] != str[R--]) 
			return false; 
	return true; 
} 

ull mpo(ull base, ull e) { 
	if (e == 0) 
		return 1; 
	if (e == 1) 
		return base; 

	ull temp = mpo(base, e/2); 
	if (e%2 ==0) 
		return (temp%MOD * temp%MOD) % MOD; 
	else
		return ((( temp%MOD * temp%MOD)%MOD) * base%MOD) % MOD; 
} 


ull mmi(ull n) { 
	return mpo(n, MOD-2); 
} 

void getph(int n, ull pre[], ull po[]) { 
	pre[0] = 0; 
	pre[1] = str[0]; 
	for (int i=2; i<=n; i++) 
		pre[i] = (pre[i-1]%MOD + (str[i-1]%MOD * po[i-1]%MOD)%MOD)%MOD; 
	return; 
} 

void getsh(int n, ull suf[], ull po[]) { 
	suf[0] = 0; 
	suf[1] = str[n-1]; 

	for (int i=n-2, j=2; i>=0 && j<=n; i--,j++) 
		suf[j] = (suf[j-1]%MOD + 
					(str[i]%MOD * po[j-1]%MOD)%MOD)%MOD; 
	return; 
} 

bool qr(Query q, int n, ull pre[], ull suf[], ull po[]) { 
	int L = q.L; 
	int R = q.R; 
	ull hlr = ((pre[R+1]-pre[L]+MOD)%MOD * mmi(po[L])%MOD)%MOD; 
	ull rhlr = ((suf[n-L]-suf[n-R-1]+MOD)%MOD * mmi(po[n-R-1])%MOD)%MOD; 
	if (hlr == rhlr) { 
		if (isp(L, R) == true) return true;
		else return false;
	} 
	else return false; 
} 

void pow1(ull po[], int n) { 
	po[0] = 1; 
	for(int i=1; i<=n; i++) 
		po[i] = (po[i-1]%MOD * p%MOD)%MOD; 
	return; 
} 


int main() { 
    while(scanf("%s",str)!=EOF) {
	    int n = strlen(str);
	    ull po[n+1]; 
	    pow1(po, n); 
	    ull pre[n+1], suf[n+1]; 
	    getph(n, pre, po); 
	    getsh(n, suf, po); 
        printf("%d ",n);
        int now = 1;
        while(now < n) {
            int cnt = 0;
            for(int i=0,j=now;j<n;i++,j++) {
                if(qr(Query(i,j),n,pre,suf,po) && qr(Query(i,((i+j)/2)),n,pre,suf,po)) {
                    cnt++;
                }
            }
            printf("%d ",cnt);
            now++;
        }
	    cout<<endl;
    }
	return 0;
} 
