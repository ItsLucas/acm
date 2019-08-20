#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char ch[maxn], eve[maxn];
int tot = 0;
int main()
{
    int n, x, y, z;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> ch;
    int len = strlen(ch);
    for(int i = 0; i < len; i ++)
    {
        if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
        {
            tot ++;
            eve[tot] = i;
        }
    }
    if(tot == 0)
    {
        cout<<"1\n";
        return 0;
    }
    if(!(ch[0] == 'a' || ch[0] == 'e' || ch[0] == 'i' || ch[0] == 'o' || ch[0] == 'u'))
    {
        cout<<"0\n";
        return 0;
    }
    if(tot == 1)
    {
        cout<<len<<"\n";
    }
    else{
        if(tot & 1)
        {
            cout<<eve[(tot+1)/2 + 1] - eve[(tot + 1)/2]<<"\n";
        }
    }
    return 0;
}
