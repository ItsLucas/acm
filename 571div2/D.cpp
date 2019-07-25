#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-7;
double a[100010];
long long b[100010];
double diff[100010];

inline long long round_up(double x) {
    return (long long)ceil(x);
}

inline long long round_down(double x) {
    return (long long)floor(x);
}

inline double extract(double x) {
    return x - (long long)x;
}

int main() {
    int n;
    cin>>n;
    long long intsum = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        diff[i]=extract(a[i]);
        b[i]=round_up(a[i]);
        intsum += b[i];
    }
    long long t = intsum;
    int pos = 1;
    //cout<<"t="<<t<<endl;
    while(t > 0) {
        //cout<<"diff="<<diff[pos]<<" a="<<a[pos]<<" b="<<b[pos]<<" eps="<<diff[pos] - (double)0.0f<<endl;
        if((diff[pos] - (double)0.0f > eps) || (diff[pos] - (double)0.0f < -eps)) {
            b[pos] = round_down(a[pos]);
            t--;
        }
        if(pos==n) break;
        pos++;
    }
    for(int i=1;i<=n;i++) {
        cout<<b[i]<<endl;
    }
    return 0;
}