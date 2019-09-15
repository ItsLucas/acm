#include <bits/stdc++.h>

#define Point pair<double, double>
using namespace std;

pair<double, double> ps[1001];

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    unordered_map<pair<double, double>, int, pair_hash> cnt;
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &ps[i].first, &ps[i].second);
        cnt[ps[i]]++;
    }
    unordered_map<pair<double, double>, int, pair_hash> mp;
    Point maxp;
    int maxpp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double xc = (ps[i].first + ps[j].first) / 2.0;
            double yc = (ps[i].second + ps[j].second) / 2.0;
            Point pp = make_pair(xc, yc);
            // printf("pp%lf %lf ", pp.first, pp.second);
            if (ps[i] != ps[j])
                mp[pp] += 2;
            mp[pp] += cnt[pp];
            // printf("%d\n", mp[pp]);
            cnt[pp] = 0;
            if (mp[pp] > maxpp) {
                maxpp = mp[pp];
            }
        }
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", n - maxpp);
    return 0;
}