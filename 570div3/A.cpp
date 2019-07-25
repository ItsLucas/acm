#include <iostream>

using namespace std;

int intsum(int n) {
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    while(intsum(n) % 4 != 0) {
        n++;
    }
    cout<<n<<endl;
    return 0;
}