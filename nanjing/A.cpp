#include <bits/stdc++.h>

using namespace std;
int matr(int n, int i, int j) {
    int x;
    x = min(min(i, j), min(n - 1 - i, n - 1 - j));
    if (i <= j)
        return (n * n) - (n - 2 * x) * (n - 2 * x) - (i - x) - (j - x);
    else
        return (n * n) - (n - 2 * x - 2) * (n - 2 * x - 2) + (i - x) + (j - x);
}