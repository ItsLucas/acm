#include <bits/stdc++.h>

using namespace std;

/*
0 0 0
0 1 0
0 2 0
0 3 0
1 0 0
1 1 0
1 2 1
1 3 1
2 0 0
2 1 1
2 2 1
2 3 1
3 0 0
3 1 1
3 2 1
3 3 2
*/
inline int min3(int num1, int num2, int num3) {
    int minn = (num1 < num2) ? num1 : num2;
    minn = (minn < num3) ? minn : num3;
    return minn;
}
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << min3(a, b, (a + b) / 3) << endl;
    }
    return 0;
}