#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<long long, int> three;
unordered_map<long long, int> he;
ll qm(ll a, ll b, ll c) {
    long long ans = 0, res = a;
    while (b) {
        if (b & 1)
            ans = (ans + res) % c;
        res = (res + res) % c;
        b >>= 1;
    }
    return (ll)ans;
}
ll qp(ll a, ll b, ll c) {
    ll ans = 1, res = a;
    while (b) {
        if (b & 1)
            ans = qm(ans, res, c);
        res = qm(res, res, c);
        b >>= 1;
    }
    return ans;
}

ll prime[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool Miller_Rabin(ll x) {
    ll i, j, k;
    ll s = 0, t = x - 1;
    if (x == 2)
        return true;
    if (x < 2 || !(x & 1))
        return false;
    while (!(t & 1)) {
        s++;
        t >>= 1;
    }
    for (i = 0; i < 6 && prime[i] < x; ++i) {
        ll a = prime[i];
        ll b = qp(a, t, x);
        for (j = 1; j <= s; ++j) {
            k = qm(b, b, x);
            if (k == 1 && b != 1 && b != x - 1)
                return false;
            b = k;
        }
        if (b != 1)
            return false;
    }
    return true;
}
char nc() {
    static char buf[1048576], *p1 = buf, *p2 = buf;
    if (p1 == p2) {
        p1 = buf;
        p2 = buf + fread(buf, 1, 1048576, stdin);
    }
    return *p1++;
}
double scand() {
    int sig = 1;
    double sum = 0, doub = 0.1;
    char f = nc();
    while ((f < '0' || f > '9') && f != '-')
        f = nc();
    if (f == '-') {
        sig = -1;
        f = nc();
    }
    while (f >= '0' && f <= '9') {
        sum = sum * 10 + f - '0';
        f = nc();
    }
    if (f == '.') {
        f = nc();
        while (f >= '0' && f <= '9') {
            sum += doub * (f - '0');
            doub *= 0.1;
            f = nc();
        }
    }
    sum *= sig;
    return sum;
}
long long scan() {
    int sig = 1;
    long long sum = 0;
    char f = nc();
    while ((f < '0' || f > '9') && f != '-')
        f = nc();
    if (f == '-') {
        sig = -1;
        f = nc();
    }
    while (f >= '0' && f <= '9') {
        sum = sum * 10 + f - '0';
        f = nc();
    }
    sum *= sig;
    return sum;
}
bool ss[1000010];
int zs[4000];
void cltri() {
    for (register unsigned int i = 2; i <= 1000009; ++i) {
        if (!ss[i]) {
            three.insert(make_pair(i * i * i, i));
            for (register unsigned int j = i + i; j <= 1000009; j += i) {
                ss[j] = 1;
            }
        } else {
            he.insert(make_pair(i * i * i, i));
        }
    }
    zs[0] = 0;
    for (register unsigned int i = 2; i <= 4000; ++i) {
        if (!ss[i]) {
            zs[++zs[0]] = i;
        }
    }
    return;
}

int asd[100], io = 0;
int tj() {
    //    for(int i = 1; i <= io; i ++)
    //    {
    //        cout<<asd[i]<<"  ";
    //    }
    //    cout<<endl;
    if (!io)
        return 1;
    int j = 0, maax = 0;
    asd[io + 1] = 2e9;
    for (register unsigned int i = 1; i <= io + 1; ++i) {
        if (asd[i] != asd[i - 1]) {
            maax = max(maax, j);
            j = 0;
        } else {
            j++;
        }
    }
    return maax;
}

int js(long long x) {
    // cout<<x<<"\n";

    long long k = sqrt(x);
    // cout<<"1";
    if (k * k == x)
        return 2 * js(k);
    // cout<<"2";
    if (three.count(x))
        return 3;
    // cout<<"3";
    if (he.count(x))
        return 3 * js(he[x]);
    // cout<<"4";
    if (zs[0] > k)
        k = zs[0];
    // cout<<"5";
    // cout<<"6";
    bool flag;
    io = 0;
    for (register unsigned int i = 2; i <= k; ++i) {
        // cout<<"\n"<<x;
        if (!ss[i] && x % i == 0) {
            flag = 0;
            x /= i;
            asd[++io] = i;
            while (x % i == 0) {
                // cout<<"**\n"<<x;
                flag = 1;
                asd[++io] = i;
                x /= i;
            }
            if (!flag) {
                // cout<<"7";
                return 1;
            }
            if (x < 1000009 && (!ss[x])) {
                if (x != 1)
                    asd[++io] = x;
                return tj();
            }
        }
    }

    // cout<<"9";

    return tj();
}
int main() {
    int tt;
    long long x;
    cltri();
    tt = scan();
    while (tt--) {
        x = scan();
        if (x == 1)
            printf("1\n");
        if (Miller_Rabin(x))
            printf("1\n");
        else
            printf("%d\n", js(x));
    }
    return 0;
}