#include <bits/stdc++.h>

using namespace std;

struct node {
    char c;
    int x;
};

static constexpr int maxn = 1000010;
int n, k;
char a[maxn], b[maxn];
void work(char x[]) {
    scanf("%s", x);
    stack<node> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top().c != x[i]) {
            s.push({x[i], 0});
        }
        s.top().x++;
        if (s.top().x == k) {
            s.pop();
        }
    }
    int pos = 0;
    while (!s.empty()) {
        node p = s.top();
        s.pop();
        for (int i = 0; i < p.x; i++) {
            x[pos++] = p.c;
        }
    }
    x[pos++] = '\0';
}

int main() {
    scanf("%d %d", &n, &k);
    work(a);
    work(b);
    if (!strcmp(a, b)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}