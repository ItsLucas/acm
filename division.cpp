#include <bits/stdc++.h>

using namespace std;

int n,dn,cnt;
bool flag, first = true;
char nums[11], d[10] = {'0','1','2','3','4','5','6','7','8','9'};

bool check() {
    //cout<<n<<" "<<dn<<endl;
    sprintf(nums, "%05d%05d", n, dn);
    //cout<<nums<<endl;
    for (int i = 0; i < 10; i++) {
        cnt = 0;
        for (int k = 0; k < 10; k++) {
            if (nums[k] == d[i])
                cnt++;
        }
        if (cnt != 1)
            return 0;
    }
    return 1;
}

int main() {
    int N;
    bool flag, first = 1;
    while (1) {
        cin>>N;
        if (N==0) break;
        if (first==0) {
            printf("\n");
        }
        flag = 0;
        dn = 1234;
        while (dn <= 98765) {
            n = N * dn;
            if (n > 98765)
                break;
            if (check()) {
                printf("%05d / %05d = %d\n", n, dn, N);
                flag = 1;
            }
            dn++;
        }
        if (!flag)
            cout<<"There are no solutions for "<<N<<"."<<endl;
        first = 0;
    }
    return 0;
};