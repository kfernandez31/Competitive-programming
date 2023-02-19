#include <bits/stdc++.h>
using namespace std;

const int NEUTRAL_ELEM = 0;
const int maxN = 1 << 19;
int n, q;

int tree[maxN << 1];

inline int add(int x, int y) {
    return x ^ y;
}

void update(int v, int x) {
    v += maxN;
    tree[v] = x;
    for (v /= 2; v > 0; v /= 2) {
        tree[v] = add(tree[2 * v], tree[2 * v + 1]);
    }
}

int query(int l, int r) {
    auto acc = NEUTRAL_ELEM;
    for (
        l += maxN - 1, r += maxN + 1;
        r - l > 1;
        l /= 2, r /= 2
    ) {
        if (l % 2 == 0) {
            acc = add(acc, tree[l + 1]);
        }
        if (r % 2 == 1) {
            acc = add(acc, tree[r - 1]);
        }
    }
    return acc;
}

void init() {
    for (int i = 1; i <= n; i++) {
        cin >> tree[i + maxN];
    }
    for (int i = maxN; i >= 1; i--) {
        tree[i] = add(tree[2 * i], tree[2 * i + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    init();

    while (q) {
        int a, b;
        string cmd;
        cin >> cmd >> a >> b;
        if (cmd == "czytaj") {
            cout << query(a, b) << "\n";
            q--;
        } else if (cmd == "zamien") {
            int prev_a = tree[a + maxN], prev_b = tree[b + maxN];
            update(a, prev_b);
            update(b, prev_a);
            q--;
        }
    }

    return 0;
}
