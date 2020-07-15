#include <bits/stdc++.h>

using namespace std;
#define maxn 1000005
char s[maxn];
char p[maxn];
int b[maxn];

/*
manacherģ��
���봮 s ����� �� p
Ȼ�������һ��b���飬 b[i]������iΪ���ĵ�����Ĵ��İ뾶
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
        ��Ϊ����Ҫ��Ļ��Ĵ�����һ����4�ı���
        �õ�һ������������ ԭ��s:abrahellehhelleh
        ����֮��Ĵ�p:$#a#b#r#a#h#e#l#l#e#h#h#e#l#l#e#h#
        Ȼ����ᷢ������Ҫ��Ķ���#λ�� ���������ڵ�λ��ȫ������
        */
        if (i & 1) {
            //��һ�ǵ�ǰλ�û��Ĵ�����
            int cur = b[i] - 1;
            /*
                    ֱ��cur���ĵı���Ϊֹ,�����ǿ���
               �������ִ�baaaab->���cur=7,
                    ������4�ı�����������Ĵ����а�����������Ҫ����ַ���
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
                ����ط�ͬ�� baaaaaab ��Ȼ��������4�ı�����
                ���ǵ�ǰ���ȵĴ�����������Ҫ��Ĵ� û�������������ѭ�� tle
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
        ������ǲ��󶮣�������������е����Լ�����һ��
        printf("s:%s\np:%s\n",s+1,p);
        int len=strlen(p);
        for(int i=1;i<=len;i++) printf("%d:%c-%d ",i,p[i],b[i]);
        printf("\n");
                */
    }
    return 0;
}