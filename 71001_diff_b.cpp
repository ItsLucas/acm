#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;

struct bigin {
    int size;
    int a[maxn];
} a, b, c;

bigin scan() {
    bigin temp;
    char s[maxn];
    cin >> s;
    temp.size = strlen(s);
    temp.a[0] = 0;
    for (int i = 1; i <= temp.size; i++) {
        temp.a[i] = s[temp.size - i] - '0';
    }
    for (int i = temp.size + 1; i < maxn; i++) {
        temp.a[i] = 0;
    }
    return temp;
}

void prin(bigin temp) {
    cout << "^^" << temp.size << "  \n";
    for (int i = 1; i <= temp.size; i++) {
        cout << temp.a[i] << " ";
    }
    cout << "\n";
    return;
}

bigin cl(bigin i, int k) {
    bigin temp;
    int x = k, y = i.size;
    while (y) {
        temp.a[x] = i.a[y];
        x--;
        y--;
    }
    while (x) {
        temp.a[x] = 0;
        x--;
    }
    temp.size = k;
    return temp;
}
bool pd(bigin &an, bigin &ad1, bigin &ad2, bool fg) {
    int len = max(an.size, ad1.size);
    bool flag = 0;
    int two = 0;
    int i, res = 0;
    while (ad2.a[two + 1] == 0) {
        two++;
        res--;
    }
    for (i = 1; i <= len; i++) {
        if (!flag) {
            if (an.a[i] != ad1.a[i]) {
                flag = 1;
                res += i - 1;
                i--;
            } else
                continue;
        } else {
            // cout <<"^^" <<i<<" "<<ad1.a[i]<<" "<<two+1<<" "<<ad2.a[two+1]<<"
            // "<<an.a[i]<<"\n";
            if ((ad1.a[i] + ad2.a[two + 1]) % 10 == an.a[i]) {
                ad2.a[two + 2] += (ad1.a[i] + ad2.a[two + 1]) / 10;
                two++;
            } else {
                // cout<<"^^";
                return false;
            }
        }
    }
    if (ad2.a[two + 1] > 0)
        return false;
    // cout<<"qwq"<<two<<"\n";
    if (two < ad2.size) {
        // cout<<"$$";
        return false;
    }
    // bigin aa, bb, cc;
    int xx, yy, zz, add = 0;
    zz = an.size - c.size;
    // if(res < 0) add = 0 - res;
    if (fg) {
        xx = ad1.size - a.size;
        yy = res;
    } else {
        xx = res;
        yy = ad1.size - b.size;
    }
    add -= (min(xx, min(yy, zz)));
    xx += add;
    yy += add;
    zz += add;
    cout << xx << " " << yy << " " << zz << "\n";
    return true;
}
bigin jw(bigin uu) {
    bigin temp;
    temp.size = uu.size + 1;
    for (int i = 1; i <= uu.size; i++) {
        temp.a[i + 1] = uu.a[i];
    }
    temp.a[1] = 0;
    temp.a[temp.size + 1] = 0;
    return temp;
}

bigin x, aa, bb, cc;
int main() {
    int tt;
    bool flag = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> tt;
    // cout<<"**";
    while (tt--) {
        a = scan();
        b = scan();
        c = scan();
        //        prin(a);
        //        prin(b);
        //        prin(c);

        if (a.size < c.size)
            aa = cl(a, c.size);
        else
            aa = a;
        if (b.size < c.size)
            bb = cl(b, c.size);
        else
            bb = b;

        // cc.a[temp.size + 1] = 999;

        cc = cl(c, aa.size);
        x = b;
        flag = pd(cc, aa, x, 1);
        if (flag)
            continue;
        // cout<<"!";
        // prin(cc);
        cc = jw(cc);
        x = b;
        //        prin(cc);
        //        prin(aa);
        //        prin(x);
        flag = pd(cc, aa, x, 1);
        if (flag)
            continue;
        // cout<<"^";

        cc = cl(c, bb.size);
        x = a;
        flag = pd(cc, bb, x, 0);
        if (flag)
            continue;
        // cout<<"$$";

        cc = jw(cc);
        x = a;
        flag = pd(cc, bb, x, 0);
        if (flag)
            continue;
        // cout<<"^";

        cout << "-1\n";
    }
}