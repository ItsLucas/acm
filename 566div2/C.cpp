#include <bits/stdc++.h>

using namespace std;

bool isvowel(char x) {
    if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return true;
    return false;
}

struct words {
    string word;
    int vc;
    char fv;
    char lv;
}w[100010];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>w[i].word;
        for(char i : w[i].word) {
            if(isvowel(i)) {
                w[i].vc++;
                if(w[i].fv==0) {
                    w[i].fv=i;
                    continue;
                }
                if(w[i].lv==0) {
                    w[i].lv=i;
                    continue;
                }
            }
        }
    }
    return 0;
}