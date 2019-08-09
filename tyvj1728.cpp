#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    t;

int main() {
    int n;
    cin >> n;
    int op, arg;
    for (int i = 1; i <= n; i++) {
        cin >> op >> arg;
        switch (op) {
        case 1: {
            t.insert(arg);
            break;
        }
        case 2: {
            t.erase(arg);
            break;
        }
        case 3: {
            cout << t.order_of_key(arg) << endl;
            break;
        }
        case 4: {
            cout << *t.find_by_order(arg - 1) << endl;
            break;
        }
        case 5: {
            cout << *--t.lower_bound(arg) << endl;
            break;
        }
        case 6: {
            cout << *t.upper_bound(arg) << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}