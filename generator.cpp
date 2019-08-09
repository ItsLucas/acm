#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
using namespace std;

template <typename... types> string format(const char *format, types... args) {
    char buff[256];
    sprintf(buff, format, args...);
    return buff;
}

int main(int, char *[]) {

    srand(time(NULL));

    for (int i = 1; i <= 10; i++) {
        freopen(format("test-%03d.in", i).data(), "w", stdout);
        // printf("I am test input %d.\n", i);
        int t = 2450 + (rand() % 50);

        printf("%d\n", t);
        while (t-- > 0) {
            int rnd = 1e9 + (rand() % 1000000000);
            int hp = rand() % 400;
            printf("%d %d\n", rnd, hp);
        }
    }
    // CON indicates console on Windows platform
    freopen("CON", "w", stdout);
    printf("I am back.\n");
    return 0;
}