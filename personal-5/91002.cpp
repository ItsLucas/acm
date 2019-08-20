#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

static constexpr int MAXN = 1e5 + 5;

struct Point {
    int x;
    int y;
    int isl;
    inline bool operator<(const Point &p) const { return x < p.x; }
};

struct Line {
    Point start, end;
    inline bool operator<(const Line &l) const { return start.y > l.start.y; }
};
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
        q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;
    return false;
}

tree<Line, null_type, less<Line>, rb_tree_tag,
     tree_order_statistics_node_update>
    tr;

Point ps[200010];

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        tr.clear();
        int x, y;
        char c;
        int pos = 1;
        for (int i = 1; i <= k; i++) {
            scanf("%d %d %c", &x, &y, &c);
            switch (c) {
            case 'L': {
                ps[pos].x = 0;
                ps[pos].y = y;
                ps[pos].isl = 1;
                pos++;
                ps[pos].x = x;
                ps[pos].y = y;
                ps[pos].isl = 0;
                pos++;
                break;
            }
            case 'R': {
                ps[pos].x = x;
                ps[pos].y = y;
                ps[pos].isl = 1;
                pos++;
                ps[pos].x = n;
                ps[pos].y = y;
                ps[pos].isl = 0;
                pos++;
                break;
            }
            case 'U': {
                ps[pos].x = x;
                ps[pos].y = y;
                ps[pos].isl = 1;
                pos++;
                ps[pos].x = x;
                ps[pos].y = m;
                ps[pos].isl = 0;
                pos++;
                break;
            }
            case 'D': {
                ps[pos].x = x;
                ps[pos].y = y;
                ps[pos].isl = 1;
                pos++;
                ps[pos].x = x;
                ps[pos].y = 0;
                ps[pos].isl = 0;
                pos++;
                break;
            }
            default:
                break;
            }
        }
        pos--;
        sort(ps + 1, ps + pos + 1);
        for (int i = 1; i <= pos; i++) {
            if (ps[i].isl) {
            }
        }
    }
}