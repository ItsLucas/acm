#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int L = 100010; 

string a, b;

string add(string a, string b)
{
    string ans;
    int na[L] = {0};
    int nb[L] = {0};
    int la = a.size();
    int lb = b.size();
    for (int i = 0; i < la; i++) 
        na[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; i++) 
        nb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0; i < lmax; i++) 
    {
        na[i] += nb[i];
        na[i + 1] += na[i] / 10;
        na[i] %= 10;
    } 
    if (na[lmax]) lmax++;
    for (int i = lmax - 1; i >= 0; i--) 
        ans += na[i] + '0';
    return ans;
}

int compare(string a,string b){
	if(a.size()>b.size())return 1;//a大于b
	else if(a.size()<b.size())return -1;//a<b
	else{
		for(int i=0;i<=a.size();i++){
			if(a[i]>b[i])return 1;
			else if(a[i]<b[i])return -1;
		}
		return 0;//两个数相等 
	} 
}

int main()
{
    string a,b,c;
    int n;
    cin>>n;
    cin>>a;
    if(n%2==1) { //1234567
        int pos = n/2;
        int ii=0,jj=0;
        for(int i=pos;i>=0;i--) {
            if(ii!=0) break;
            if(a[i]!='0') ii=i;
        }
        for(int j=pos;j<=n;j++) {
            if(jj!=0) break;
            if(a[j]!='0') jj=j;
        }
        //cout<<ii<<" "<<jj<<endl;
        if(ii==jj) {
            b=a.substr(0,ii);
            c=a.substr(ii);
            //cout<<b<<endl;
            //cout<<c<<endl;
            string d=add(b,c);
            b=a.substr(0,ii+1);
            c=a.substr(ii+1);
            string d2 = add(b,c);
            if(compare(d,d2)==-1) cout<<d<<endl;
            else cout<<d2<<endl;
            return 0;
        }
        else {
            b=a.substr(0,ii);
            c=a.substr(ii);
            //cout<<b<<endl;
            //cout<<c<<endl;
            string d=add(b,c);
            b=a.substr(0,jj);
            c=a.substr(jj);
            string d2 = add(b,c);
            if(compare(d,d2)==-1) cout<<d<<endl;
            else cout<<d2<<endl;
            return 0;
        }
    }
    else { //123456
        int pos = n/2-1;
        int ii=0,jj=0;
        for(int i=pos;i>=0;i--) {
            if(ii!=0) break;
            if(a[i]!='0') ii=i;
        }
        for(int j=pos;j<=n;j++) {
            if(jj!=0) break;
            if(a[j]!='0') jj=j;
        }
        //cout<<ii<<" "<<jj<<endl;
        if(ii==jj) {
            b=a.substr(0,ii+1);
            c=a.substr(ii+1);
            //cout<<b<<endl;
            //cout<<c<<endl;
            string d=add(b,c);
            cout<<d<<endl;
            return 0;
        }
        else {
            b=a.substr(0,ii+1);
            c=a.substr(ii+1);
            //cout<<b<<endl;
            //cout<<c<<endl;
            //cout<<"sum1="<<add(b,c)<<endl;
            string d=add(b,c);
            b=a.substr(0,jj);
            c=a.substr(jj);
            //cout<<b<<endl;
            //cout<<c<<endl;
            //cout<<"sum2="<<add(b,c)<<endl;
            string d2 = add(b,c);
            if((compare(d,d2)==-1)&&d[0]!='0') cout<<d<<endl;
            else cout<<d2<<endl;
            return 0;
        }
    }
    return 0;
}