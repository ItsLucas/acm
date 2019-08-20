#include <bits/stdc++.h>

using namespace std;

#define M_PI 3.1415926535897932384

int main() {
    int t;
    double l, a;
    cout.setf(ios::fixed);
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%lf %lf", &l, &a);
        double b = a / (1.0 * 360);
        b *= M_PI * l * l;
        //  printf("%lf\n", b);
        a = a / (180 * 1.0);
        double c = 0.5 * sin(a * M_PI) * l * l;
        //    printf("%lf\n", c);
        b -= c;
        printf("%.6lf\n", b);
    }
    return 0;
}