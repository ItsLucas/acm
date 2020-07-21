#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> s;
char pattern[8] = {' ', 'a', 'b', 'a', 'c', 'a', 'b', 'a'};
inline void popstack() {
    while (!s.empty())
        s.pop();
}
void getNext(string needle, int next[]) {
    int j = 0;
    int k = -1;

    next[0] = -1;

    while (j < needle.length()) {
        if (k == -1 || needle[j] == needle[k]) {
            ++j;
            ++k;
            next[j] = k;

            //                if (needle[j] != needle[k]){
            //                    next[j] = k;
            //                } else{
            //                    next[j] = next[k];
            //                }

        } else {
            k = next[k];
        }
    }
}
int countFreq(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M) {
            res++;
            j = 0;
        }
    }
    return res;
}
int strStr(string haystack, string needle) {
    if (needle.length() == 0) {
        return 0;
    }
    int next[needle.length()];
    getNext(needle, next);

    int i = 0, j = 0;
    while (i < (int)haystack.length() && j < (int)needle.length() &&
           (i - j) < (int)(haystack.length() - needle.length()) + 1) {

        if (j == -1 || haystack[i] == needle[j]) {
            j++;
            i++;
        } else {
            j = next[j];
        }
    }
    if (j == needle.length()) {
        return i - needle.length();
    } else {
        return -1;
    }
}
bool check() {
    for (int i = 7; i >= 1; i--) {
        char c = s.top();
        s.pop();
        if (c == '?' || c == pattern[i])
            continue;
        else {
            return false;
        }
    }
    return true;
}

int pc(char s) {
    if (s == '?')
        putchar('z');
    else
        putchar(s);
}
char gc(char s) {
    if (s == '?')
        return 'z';
    else
        return s;
}
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        cin >> str;
        if (strStr(str, "abacaba") != -1) {
            if (countFreq("abacaba", str) == 1) {
                cout << "Yes" << endl;
                for (int i = 0; i < n; i++) {
                    pc(str[i]);
                }
                cout << endl;
                continue;
            } else {
                cout << "No" << endl;
                continue;
            }
        }
    be:
        int start = 99999, end = 99999;
        for (int i = 0; i < n; i++) {
            if (s.size() == 7) {
                if (check()) {
                    end = i - 1;
                    start = i - 7;
                    break;
                } else {
                    popstack();
                }
            } else {
                if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' ||
                    str[i] == '?') {
                    s.push(str[i]);
                } else {
                    popstack();
                }
            }
        }
        if (s.size() == 7) {
            if (check()) {
                end = n - 1;
                start = n - 7;
            } else {
                popstack();
            }
        }
        string str2;
        if (start != 99999) {
            cout << "Yes" << endl;

            for (int i = 0; i < start; i++) {
                str2.push_back(gc(str[i]));
            }
            int j = 1;
            for (int i = start; i <= end; i++) {
                str2.push_back(pattern[j]);
                j++;
            }
            for (int i = end + 1; i < n; i++) {
                str2.push_back(gc(str[i]));
            }
            if (countFreq("abacaba", str2) == 1)
                cout << str2 << endl;
            else {
                for (int i = 0; i < n; i++) {
                    if (str[i] == '?') {
                        str[i] = 'z';
                        goto be;
                    }
                }
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}