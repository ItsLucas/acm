#include <bits/stdc++.h>

using namespace std;

char m[501][501];
int h,w;


bool notedge(int a,int b) {
    if(a==0) return false;
    if(a==h) return false;
    if(b==0) return false;
    if(b==w) return false;
    return true;
}

bool iscenter(int i,int j) {
    if(m[i][j]=='*') {
        if(m[i+1][j]=='*'){
            if(m[i-1][j]=='*'){
                if(m[i][j+1]=='*'){
                    if(m[i][j-1]=='*'){
                        return true;
                    }
                }   
            }
        }
    }
    return false;
}
int scan(int a,int b,int &c){
    //cout<<"Enter scan"<<a<<" "<<b<<endl;
    int aa=a,bb=b;
    while(m[aa][bb]=='*'&&notedge(aa,bb)) {
        c++;
        //cout<<aa<<" "<<bb<<endl;
        aa-=1;
        if((m[aa][bb+1]=='*')||(m[aa][bb-1]=='*')) return 0;
    }
    aa=a,bb=b;
    while(m[aa][bb]=='*'&&notedge(aa,bb)) {
        //cout<<aa<<" "<<bb<<endl;
        c++;
        aa+=1;
        if((m[aa][bb+1]=='*')||(m[aa][bb-1]=='*')) return 0;
    }
    aa=a,bb=b;
    while(m[aa][bb]=='*'&&notedge(aa,bb)) {
        //cout<<aa<<" "<<bb<<endl;
        c++;
        bb-=1;
        if((m[aa+1][bb]=='*')||(m[aa-1][bb]=='*')) return 0;
    }
    aa=a,bb=b;
    while(m[aa][bb]=='*'&&notedge(aa,bb)) {
        //cout<<aa<<" "<<bb<<endl;
        c++;
        bb+=1;
        if((m[aa+1][bb]=='*')||(m[aa-1][bb]=='*')) return 0;
    }
    c-=3;
    return 1;
}

int main() {
    int h,w;
    cin>>h>>w;
    int cnt_all=0;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin>>m[i][j];
            if(m[i][j]=='*') cnt_all++;
        }
    }
    int posx,posy;
    int cnt=0;
    for(int i=2;i<=h-1;i++) {
        for(int j=2;j<=w-1;j++) {
            if(iscenter(i,j)) {
                posx=i;
                posy=j;
                cnt++;
            }
        }
    }
    if(cnt!=1) {
        cout<<"NO"<<endl;
        return 0;
    }
    int c=0;
    int r = scan(posx,posy,c);
    //cout<<cnt_all<<" "<<c<<endl;
    if(r&&cnt_all==c) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}