#include <bits/stdc++.h>

using namespace std;

string s[] = {"ZHAO",  "QIAN", "SUN",   "LI",   "ZHOU", "WU",
              "ZHENG", "WANG", "CHANG", "CHAO", "YANG", "JIN"};

pair<int, string> hash1[17];
pair<int, int> pre[17];
int ci[17];
int hasher(int num) { return num % 16; }
int main() {
    int x = 1;
    for (auto i : s) {
        int num = 0;
        for (auto j : i) {
            num = 25 * num + j - 'A' + 1;
        }
        pre[x] = make_pair(x, num);
        x++;
    }
    for (int i = 0; i < 12; i++) {
        x = hasher(pre[i + 1].second);
        int t = 1;
        while (hash1[x].first != 0) {
            x++;
            t++;
        }
        hash1[x] = make_pair(x, s[i]);
        ci[x] = t;
    }
    int aslsum = 0;
    for (auto i : hash1) {
        cout << i.first << " " << i.second << " " << ci[i.first] << endl;
        aslsum += ci[i.first];
    }
    cout << "ASL=" << aslsum / 12 << endl;
    return 0;
}