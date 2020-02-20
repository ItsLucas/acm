#include <bits/stdc++.h>

using namespace std;

stack<char> st;
char s[5005];
bool judge(char *str) {
    int len = strlen(str);
    if (len == 1)
        return true;
    char *ptr1 = str;
    char *ptr2 = str + len - 1;
    while (ptr2 > ptr1) {
        if (*ptr1 != *ptr2)
            return false;
        ptr1++;
        ptr2--;
    }
    return true;
}

int work(char s[]) {
    if (judge(s))
        return 0;
    st.push(s[0]);
    s++;
    return 1 + work(s);
}

int main() {
    scanf("%s", s);
    printf("%s", s);
    int len = work(s);
    while (!st.empty()) {
        printf("%c", st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}