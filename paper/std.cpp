#include <bits/stdc++.h>

using namespace std;
#define maxn 1000005
char s[maxn];
char p[maxn];
int b[maxn];

/*
manacher模板
输入串 s 处理成 串 p
然后会生成一个b数组， b[i]代表以i为中心的最长回文串的半径
*/
void manacher() {
    memset(b, 0, sizeof(b));
    int len = strlen(s + 1);
    memset(p, '\0', sizeof(p));
    p[0] = '$';
    int cnt = 1;
    for (int i = 1; i <= 2 * len + 1; i++) {
        if (i % 2 == 1)
            p[i] = '#';
        if (i % 2 == 0)
            p[i] = s[cnt++];
    }
    int mx = 0;
    int id = 0;
    for (int i = 1; i <= len * 2 + 1; i++) {
        if (mx > i)
            b[i] = min(b[2 * id - i], mx - i);
        else
            b[i] = 1;
        while (p[i - b[i]] == p[i + b[i]])
            b[i]++;
        if (b[i] + i > mx) {
            mx = b[i] + i;
            id = i;
        }
    }
}

int solve() {
    int len = strlen(s + 1) * 2 + 1;
    int ans = 0;
    for (int i = 1; i <= len; i++) {
        /*
        因为本题要求的回文串长度一定是4的倍数
        拿第一个样例举例： 原串s:abrahellehhelleh
        处理之后的串p:$#a#b#r#a#h#e#l#l#e#h#h#e#l#l#e#h#
        然后你会发现满足要求的都在#位置 而他们所在的位置全是奇数
        */
        if (i & 1) {
            //减一是当前位置回文串长度
            int cur = b[i] - 1;
            /*
                    直到cur是四的倍数为止,这种是考虑
               类似这种串baaaab->求出cur=7,
                    不满足4的倍数但是其回文串当中包含了我们想要求的字符串
            */
            while (cur % 4 != 0)
                cur--;

            while (cur > ans) {
                int r = cur / 2;
                if ((b[i + r] - 1) >= r && (b[i - r] - 1) >= r) {
                    ans = cur;
                    break;
                }
                /*
                这个地方同理 baaaaaab 虽然长度满足4的倍数，
                但是当前长度的串并不是我们要求的串 没有这个条件会死循环 tle
                */
                cur = cur - 4;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        manacher();
        printf("%d\n", solve());
        /*
        如果还是不大懂，可以输出过程中的量自己手推一下
        printf("s:%s\np:%s\n",s+1,p);
        int len=strlen(p);
        for(int i=1;i<=len;i++) printf("%d:%c-%d ",i,p[i],b[i]);
        printf("\n");
                */
    }
    return 0;
}