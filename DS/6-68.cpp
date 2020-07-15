void build(node *root, int n, int *d) {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (!i) {
            x = 1;
            y = d[i] + x - 1;
            root[i]->child = root[x];
            for (int j = x; j < y; j++) {
                root[j]->ne = root[j + 1];
            }
        } else {
            if (d[i] > 1) {
                x = y + 1;
                y = x + d[i] - 2;
                root[i]->child = root[x];
                for (int j = x; j < y; j++) {
                    root[j]->ne = root[j + 1];
                }
            }
        }
    }
}

string intToA(int n, int radix) {
    string ans = "";
    do {
        int t = n % radix;
        if (t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}