#include <bits/stdc++.h>

using namespace std;

static constexpr int inf = 0x7fff7f7f;

struct player {
    string name;
    int hp;
    int at;
    int df;
};
bool check(player a, player b) { // 0:draw 1:A 2:B
    int dab = max(0, a.at - b.df);
    int dba = max(0, b.at - a.df);
    if (dab == 0)
        dab = inf;
    else {
        int tmp = b.hp / dab;
        if (tmp * dab != b.hp)
            tmp++;
        dab = tmp;
    }
    if (dba == 0)
        dba = inf;
    else {
        int tmp = a.hp / dba;
        if (tmp * dba != a.hp)
            tmp++;
        dba = tmp;
    }
    if (dab < dba)
        return true;
    return false;
}
player ps[101];
string cache[200010];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].name >> ps[i].hp >> ps[i].at >> ps[i].df;
    }
    int cnt = 0;
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                if ((check(ps[i], ps[j]) == 1 && check(ps[j], ps[k]) == 1 &&
                     check(ps[k], ps[i]) == 1) ||
                    (check(ps[j], ps[i]) == 1 && check(ps[k], ps[j]) == 1 &&
                     check(ps[i], ps[k]) == 1)) {
                    cnt++;
                    cache[pos++] = ps[i].name;
                    cache[pos++] = ps[j].name;
                    cache[pos++] = ps[k].name;
                }
            }
        }
    }
    pos--;
    cout << cnt << endl;
    for (int i = 1; i <= pos; i += 3) {
        cout << cache[i] << " " << cache[i + 1] << " " << cache[i + 2] << endl;
    }
    return 0;
}