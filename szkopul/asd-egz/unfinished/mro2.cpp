#include <bits/stdc++.h>
using namespace std;

const int maxN = 1 << 19;

int n, q;
int arr[maxN];
int tree[2 * maxN];

void update(int l, int r, int x) {
    for (
        l += maxN - 1, r += maxN + 1;
        r - l > 1;
        l /= 2, r /= 2
    ) {
        if (l % 2 == 0) {
            tree[l + 1] = f(tree[l + 1], x);
        }
        if (r % 2 == 1) {
            tree[r - 1] = f(tree[r - 1], x);
        }
    }
}

int query(int v) {
    int res = 0;
    for (v += maxN; v > 0; v /= 2) {
        res = f(res, tree[v]);
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int pos;
        cin >> pos;
        arr[pos]++;
    }


    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;

        int lcnt = 0, rcnt = 0;
        if (l <= d - 1) {
            lcnt = update(l, d - 1, lcnt);
        } 
        if (d + 1 <= r) {
            rcnt = update(d + 1, r, -rcnt);
        } 
        
        cout << lcnt + rcnt << "\n";
        update(d, d, lcnt + rcnt);
    }

    return 0;
}