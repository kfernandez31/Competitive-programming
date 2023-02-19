#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;
const int maxN = 1 << 15;

int arr[maxN];
int n, k;
int tree[2 * maxN];
int buf_write[maxN];
int buf_read[maxN];

inline static int safe_mod(int x) {
    return (x % MOD + MOD) % MOD;
}

int f(int a, int b) {
    return safe_mod(a + b);
}

void update(int v, int x) {
    v += maxN;
    tree[v] = x;
    for (v /= 2; v > 0; v /= 2) {
        tree[v] = f(tree[2 * v], tree[2 * v + 1]);
    }
}

int query(int l, int r) {
    int res = 0;
    for (
        l += maxN - 1, r += maxN + 1;
        r - l > 1;
        l /= 2, r /= 2
    ) {
        if (l % 2 == 0) {
            res = f(res, tree[l + 1]);
        }
        if (r % 2 == 1) {
            res = f(res, tree[r - 1]);
        }
    }
    return res;
}

int solve() {   
    for (int i = 0; i < n; i++) {
        buf_read[i] = 1;
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            buf_write[j] = query(arr[j] + 1, n);
            update(arr[j], buf_read[j]);
        }
        memcpy(buf_read, buf_write, sizeof(buf_write));
        memset(tree, 0, sizeof(tree));
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = f(res, buf_read[i]);
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve() << "\n";

    return 0;
}
