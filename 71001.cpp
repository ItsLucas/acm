#include <bits/stdc++.h>

using namespace std;

const int maxn = 100030;

struct bign {
    int d[maxn], len;

    void clean() {
        while (len > 1 && !d[len - 1])
            len--;
    }

    bign() {
        memset(d, 0, sizeof(d));
        len = 1;
    }
    bign(int num) { *this = num; }
    bign(char *num) { *this = num; }
    bign operator=(const char *num) {
        memset(d, 0, sizeof(d));
        len = strlen(num);
        for (int i = 0; i < len; i++)
            d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    bign operator=(int num) {
        char s[20];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    bign operator+(const bign &b) {
        bign c = *this;
        int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] += b.d[i];
            if (c.d[i] > 9)
                c.d[i] %= 10, c.d[i + 1]++;
        }
        while (c.d[i] > 9)
            c.d[i++] %= 10, c.d[i]++;
        c.len = max(len, b.len);
        if (c.d[i] && c.len <= i)
            c.len = i + 1;
        return c;
    }
    bign operator-(const bign &b) {
        bign c = *this;
        int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0)
                c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0)
            c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    bign operator*(const bign &b) const {
        int i, j;
        bign c;
        c.len = len + b.len;
        for (j = 0; j < b.len; j++)
            for (i = 0; i < len; i++)
                c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
            c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    bign operator/(const bign &b) {
        int i, j;
        bign c = *this, a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1))
                    break;
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    bign operator%(const bign &b) {
        int i, j;
        bign a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1))
                    break;
            a = a - b * j;
        }
        return a;
    }
    bign operator+=(const bign &b) {
        *this = *this + b;
        return *this;
    }

    bool operator<(const bign &b) const {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i])
                return d[i] < b.d[i];
        return false;
    }
    bool operator>(const bign &b) const { return b < *this; }
    bool operator<=(const bign &b) const { return !(b < *this); }
    bool operator>=(const bign &b) const { return !(*this < b); }
    bool operator!=(const bign &b) const { return b < *this || *this < b; }
    bool operator==(const bign &b) const {
        return !(b < *this) && !(b > *this);
    }

    string str() const {
        char s[maxn] = {};
        for (int i = 0; i < len; i++)
            s[len - 1 - i] = d[i] + '0';
        return s;
    }
};

istream &operator>>(istream &in, bign &x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream &operator<<(ostream &out, const bign &x) {
    out << x.str();
    return out;
}

bign a, b, c, ten, oa, ob, oc, gen;

int main() {
    int t, cnta, cntb, cntc;
    cin >> t;
    ten = bign(10);
    while (t-- > 0) {
        oa = bign();
        ob = bign();
        oc = bign();
        cin >> oa >> ob >> oc;
        // align a,c
        a = oa, b = ob, c = oc;
        cnta = 0, cntb = 0, cntc = 0;
        while (a.len < c.len) {
            a = a * ten;
            cnta++;
        }
        while (c.len < a.len) {
            c = c * ten;
            cntc++;
        }
        // cout << a << " " << c << " " << a.len << " " << c.len << " " << endl;
        int i;
        for (i = a.len; i >= 1; i--) {
            // cout << "Comparing " << a.d[i] << " " << c.d[i] << endl;
            if (a.d[i] != c.d[i]) {
                break;
            }
        }
        if (b.len < a.len) {
            for (int p = i; p <= a.len; p++) {
                b = b * ten;
                cntb++;
            }
        }
        if (b.len > a.len) {
            for (int p = i; p <= a.len; p++) {
                b = b / ten;
                cntb--;
            }
        }
        gen = a + b;
        // cout << gen << endl;
        if (c == gen) {
            if (cntb < 0) {
                cnta += abs(cntb);
                cntc += abs(cntb);
                cntb += abs(cntb);
            }
            printf("%d %d %d\n", cnta, cntb, cntc);
            continue;
        }
        // align b,c
        a = ob, b = oa, c = oc;
        cnta = 0, cntb = 0, cntc = 0;
        while (a.len < c.len) {
            a = a * ten;
            cnta++;
        }
        while (c.len < a.len) {
            c = c * ten;
            cntc++;
        }
        for (i = a.len; i >= 1; i--) {
            // cout << "Comparing " << a.d[i] << " " << c.d[i] << endl;
            if (a.d[i] != c.d[i]) {
                break;
            }
        }
        if (b.len < a.len) {
            for (int p = i; p <= a.len; p++) {
                b = b * ten;
                cntb++;
            }
        }
        if (b.len > a.len) {
            for (int p = i; p <= a.len; p++) {
                b = b / ten;
                cntb--;
            }
        }
        gen = a + b;
        // cout << gen << endl;
        if (c == gen) {
            if (cntb < 0) {
                cnta += abs(cntb);
                cntc += abs(cntb);
                cntb += abs(cntb);
            }
            printf("%d %d %d\n", cnta, cntb, cntc);
            continue;
        }
        // align a,jc
        a = oa, b = ob, c = oc;
        cnta = 0, cntb = 0, cntc = 0;
        while (c.len < a.len + 1) {
            c = c * ten;
            cntc++;
        }
        // cout << a << " " << c << " " << a.len << " " << c.len << " " << endl;
        for (i = a.len; i >= 1; i--) {
            // cout << "Comparing " << a.d[i] << " " << c.d[i] << endl;
            if (a.d[i] != c.d[i]) {
                break;
            }
        }
        // cout << "i=" << i << endl;
        if (b.len < a.len) {
            for (int p = i; p < a.len; p++) {
                b = b * ten;
                cntb++;
            }
        }
        if (b.len > a.len) {
            for (int p = i; p < a.len; p++) {
                b = b / ten;
                cntb--;
            }
        }
        // cout << b << endl;
        gen = a + b;
        // cout << gen << endl;
        if (c == gen) {
            if (cntb < 0) {
                cnta += abs(cntb);
                cntc += abs(cntb);
                cntb += abs(cntb);
            }
            printf("%d %d %d\n", cnta, cntb, cntc);
            continue;
        }
        // align b,jc
        a = ob, b = oa, c = oc;
        cnta = 0, cntb = 0, cntc = 0;
        while (c.len < a.len + 1) {
            c = c * ten;
            cntc++;
        }
        // cout << a << " " << c << " " << a.len << " " << c.len << " " << endl;
        for (i = a.len; i >= 1; i--) {
            // cout << "Comparing " << a.d[i] << " " << c.d[i] << endl;
            if (a.d[i] != c.d[i]) {
                break;
            }
        }
        // cout << "i=" << i << endl;
        if (b.len < a.len) {
            for (int p = i; p < a.len; p++) {
                b = b * ten;
                cntb++;
            }
        }
        if (b.len > a.len) {
            for (int p = i; p < a.len; p++) {
                b = b / ten;
                cntb--;
            }
        }
        // cout << b << endl;
        gen = a + b;
        // cout << gen << endl;
        if (c == gen) {
            if (cntb < 0) {
                cnta += abs(cntb);
                cntc += abs(cntb);
                cntb += abs(cntb);
            }
            printf("%d %d %d\n", cnta, cntb, cntc);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}