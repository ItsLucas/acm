#include <bits/stdc++.h>

using namespace std;

int main() {
    int d;
    cin >> d;
    long long n, m;
    stringstream ss;
    ss << "long long a" << d << "[]={";
    while (cin >> n >> m) {
        ss << m << ",";
    }
    ss << "};";
    cout << ss.str() << endl;
    return 0;
}