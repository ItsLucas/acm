

#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;

int dp[maxn], sum[maxn];

int n, s1[maxn], s2[maxn];

int main()

{

    while (~scanf("%d", &n))

    {

        int l = 0, r = 0;

        dp[0] = -10000000;

        sum[0] = 0;

        for (int i = 0; i < n; i++)

        {

            char s[5];

            scanf("%s", s);

            if (s[0] == 'I')

            {

                scanf("%d", &s1[++l]);

                sum[l] = sum[l - 1] + s1[l];

                dp[l] = max(dp[l - 1], sum[l]);

            }

            else if (s[0] == 'D')

            {

                l--;

            }

            else if (s[0] == 'L')

            {

                if (l != 0)

                    s2[++r] = s1[l--];

            }

            else if (s[0] == 'R')

            {

                if (r != 0)

                {

                    s1[++l] = s2[r--];

                    sum[l] = sum[l - 1] + s1[l];

                    dp[l] = max(dp[l - 1], sum[l]);
                }

            }

            else

            {

                int x;

                scanf("%d", &x);

                printf("%d\n", dp[x]);
            }
        }
    }

    return 0;
}