#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

struct Rect {
    Point bl, br, tl, tr;
};

Point l1, l2, r1, r2;
Rect re1, re2;
bool toLeft(vector<ll> rec1, int px, int py, int qx, int qy) {
    vector<ll> tmp(4, 0);
    ll start = 0;
    for (ll i = 0; i < 3; i += 2)
        for (ll j = 1; j < 4; j += 2) {
            ll sx = rec1[i];
            ll sy = rec1[j];
            tmp[start++] = (ll)px * qy - (ll)py * qx + (ll)qx * sy -
                           (ll)qy * sx + (ll)sx * py - (ll)sy * px;
        }
    if (tmp[0] <= 0 && tmp[1] <= 0 && tmp[2] <= 0 && tmp[3] <= 0)
        return true;
    return false;
}

bool isOverlap(vector<ll> &rec1, vector<ll> &rec2) {
    return !(toLeft(rec1, rec2[0], rec2[1], rec2[2], rec2[1]) ||
             toLeft(rec1, rec2[2], rec2[1], rec2[2], rec2[3]) ||
             toLeft(rec1, rec2[2], rec2[3], rec2[0], rec2[3]) ||
             toLeft(rec1, rec2[0], rec2[3], rec2[0], rec2[1]));
}

void buildrec1(Rect &r) {
    r.bl = {l1.x, l1.y};
    r.br = {r1.x, l1.y};
    r.tl = {l1.x, r1.y};
    r.tr = {r1.x, r1.y};
}

void buildrec2(Rect &r) {
    r.bl = {l2.x, l2.y};
    r.br = {r2.x, l2.y};
    r.tl = {l2.x, r2.y};
    r.tr = {r2.x, r2.y};
}

bool judge(Rect r1, Rect r2) {
    if (r1.tl.x > r2.tl.x && r1.tl.y > r2.tl.y && r1.tr.x < r2.tr.x &&
        r1.tr.y > r2.tr.y && r1.bl.x > r2.bl.x && r1.bl.y < r2.bl.y &&
        r1.br.x < r2.br.x && r1.br.y < r2.br.y)
        return true;
    return false;
}

bool judge2(Rect r1, Rect r2) {
    if (r1.tl.x > r2.tl.x && r1.tl.y >= r2.tl.y && r1.tr.x < r2.tr.x &&
        r1.tr.y >= r2.tr.y && r1.bl.x > r2.bl.x && r1.bl.y <= r2.bl.y &&
        r1.br.x < r2.br.x && r1.br.y <= r2.br.y)
        return true;
    return false;
}

int main() {
    ll t;
    scanf("%lld", &t);
    while (t-- > 0) {
        scanf("%lld %lld %lld %lld", &l1.x, &l1.y, &r1.x, &r1.y);
        scanf("%lld %lld %lld %lld", &l2.x, &l2.y, &r2.x, &r2.y);
        vector<ll> rec1 = {l1.x, l1.y, r1.x, r1.y};
        vector<ll> rec2 = {l2.x, l2.y, r2.x, r2.y};
        ll area1 = abs(l1.x - r1.x) * abs(l1.y - r1.y);
        ll area2 = abs(l2.x - r2.x) * abs(l2.y - r2.y);
        ll areaI = (min(r1.x, r2.x) - max(l1.x, l2.x)) *
                   (min(r1.y, r2.y) - max(l1.y, l2.y));
        // cout << isOverlap(rec1, rec2) << " " << area1 << " " << area2 << " "
        //<< areaI << endl;
        buildrec1(re1);
        buildrec2(re2);
        if (judge2(re1, re2) || judge2(re2, re1)) {
            if (judge(re1, re2) || judge(re2, re1)) {
                printf("6\n");
            } else
                printf("5\n");
        } else if (areaI == 0) {
            printf("3\n");
        } else if (!isOverlap(rec1, rec2)) {
            printf("3\n");
        } else if (area1 == area2 && area2 == areaI) {
            printf("2\n");
        } else if (areaI < area1 && areaI < area2) {
            printf("4\n");
        } else {
            printf("3\n");
        }
    }
    return 0;
}