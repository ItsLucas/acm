#include <bits/stdc++.h>

using namespace std;

int cnt[256];
int a1,a2;
int d[200010];

inline char convert(char c) {
    if(isupper(c)) return tolower(c);
    else if(islower(c)) return toupper(c);
}

int main() {
    string s,t;
    cin>>s;
    cin>>t;
    for(char c : t) {
        cnt[c]++;
    }
    for(int i=0;i<s.length();i++) {
        if(cnt[s[i]] > 0) {
            a1++;
            cnt[s[i]]--;
            continue;
        }
        else {
            d[i] = 1;
        }
    }
    for(int i=0;i<s.length();i++) {
        char c = convert(s[i]);
        if(!d[i]) continue;
        if(cnt[c] > 0) {
            a2++;
            cnt[c]--;
        }
    }
    cout<<a1<<" "<<a2<<endl;
    return 0;
}