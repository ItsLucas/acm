#include <bits/stdc++.h>
using namespace std;

void block(long int x) {
    vector<long long> v;
    cout << "Blocks for " << x << " : ";
    while (x > 0) {
        v.push_back(x % 2);
        x = x / 2;
    }

    // Displaying the output when
    // the bit is '1' in binary
    // equivalent of number.
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            cout << i;
            if (i != v.size() - 1)
                cout << ", ";
        }
    }
    cout << endl;
}

// Driver Function
int main() {
    block(20);
    return 0;
}
