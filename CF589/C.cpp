#include <bits/stdc++.h>

using namespace std;

vector<int> getf(int x) {
    vector<int> v;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        v.push_back(x);
    return v;
}

int main() {
    int x;
    long long n;
    vector<int> fx = getf(x);
}