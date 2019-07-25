#include <iostream>
 
using namespace std;

int x1 = 5544;
int x2 = 14421;
int x3 = 1288;
int s = 21252;
int a,b,c,d,cnt = 0;

int main(){
    while (cin>>a>>b>>c>>d){
        cnt++;
        if (a == -1 && b == -1 && c == -1 && d == -1) break;
        int sum = x1 * a + x2 * b + x3 * c;
        int k = (sum - d + s) % s;
        if (k <= 0) k += s;
        cout<<"Case "<<cnt<<": the next triple peak occurs in "<<k<<" days."<<endl;
    }
    return 0;
}
