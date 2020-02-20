#include <bits/stdc++.h>

using namespace std;
static constexpr int maxn = 2000006;
int ans[maxn], cnt;

template <class T> class vector_s : public vector<T> {
  public:
    vector_s(size_t n = 0, const T &x = T()) : vector<T>(n, x) {}
    T &operator[](size_t n) { return this->at(n); }
    const T &operator[](size_t n) const { return this->at(n); }
};

#define vector vector_s

struct node {
    int a, b;
    node(int a = 0, int b = 0) : a(a), b(b){};
};
vector<node> v[maxn];

void dfs(int x, int y, int seq) {
    if (y < 0 || v[x][y].b < seq)
        return;
    if (cnt > 2000003)
        return;
    ans[cnt++] = v[x][y].a;
    dfs(v[x][y].a, v[v[x][y].a].size() - 1, v[x][y].b);
    dfs(x, y - 1, seq);
    return;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(node(y, i));
    }
    cnt = 1;
    dfs(0, v[0].size() - 1, -1);
    for (int i = l; i < r; i++) {
        cout << ans[i % cnt] << " ";
    }
    cout << endl;
    return 0;
}
