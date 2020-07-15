#include <bits/stdc++.h>

using namespace std;

char c[6];

int main() {
    scanf("%s", c);
    if (c[2] == c[3] && c[4] == c[5])
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}