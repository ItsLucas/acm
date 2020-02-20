#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Point {
    double x, y, z;
} p[105];

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

double ac(int n) {
    double ans = 1e9;
    Point tmp;
    tmp.x = tmp.y = tmp.z = 0;
    ;
    int s = 1;
    double step = 1000;
    double esp = 0.0000001;
    while (step > esp) {
        for (int i = 1; i <= n; i++) {
            if (dist(tmp, p[s]) < dist(tmp, p[i]))
                s = i;
        }
        double Dist = dist(tmp, p[s]);
        ans = min(ans, Dist);
        tmp.x += (p[s].x - tmp.x) / Dist * step;
        tmp.y += (p[s].y - tmp.y) / Dist * step;
        tmp.z += (p[s].z - tmp.z) / Dist * step;
        step *= 0.999;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
    }
    double ans = ac(n);
    printf("%.5f\n", ans);
}