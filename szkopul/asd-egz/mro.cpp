#include <bits/stdc++.h>
using namespace std;

//const int maxN = 1 << 19;
const int maxN = 1 << 3;

int n, q;
int arr[maxN];
int tree[2 * maxN];
int lazy[2 * maxN];

void push(int v, int vl, int vr, int mid) {
    if (lazy[v] != -1) {
        lazy[2*v]   = lazy[v];
        lazy[2*v+1] = lazy[v];

        tree[2*v]   = lazy[v] * (mid - vl + 1);
        tree[2*v+1] = lazy[v] * (vr - (mid + 1) + 1);

        lazy[v] = -1;
    }
}

void update(int ql, int qr, int val, int v, int vl, int vr) {
    if (qr < vl || vr < ql) {
        return;
    } 
    if (ql <= vl && vr <= qr) {
        tree[v] = val;
        lazy[v] = val;
        return;
    } 
    int mid = (vl + vr) / 2;
    push(v, vl, vr, mid);
    update(ql, qr, val, 2*v, vl, mid);
    update(ql, qr, val, 2*v+1, mid+1, vr);
}

void update(int q1, int q2, int val) {
    update(q1, q2, val, 1, 1, maxN);
}

int query(int ql, int qr, int v, int vl, int vr) {
    if (qr < vl || vr < ql) {
        return 0;
    } 
    if (ql <= vl && vr <= qr) {
        return tree[v];
    } 
    int mid = (vl + vr) / 2;
    push(v, vl, vr, mid);
    return query(ql, qr, 2*v, vl, mid)
        + query(ql, qr, 2*v+1, mid+1, vr);
}

int query(int q1, int q2) {
    return query(q1, q2, 1, 1, maxN);
}

void build() {
    for (int i = maxN; i >= 1; i--) {
        lazy[i] = -1;
        tree[i] = tree[2*i] + tree[2*i+1];
    }

    for (int i = 1 + maxN; i <= n + maxN; i++) {
        lazy[i] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        tree[pos + maxN]++;
    }

    build();

    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;

        int total_cnt = query(l, r);
        int d_cnt = query(d, d);

        cout << total_cnt - d_cnt << "\n";

        update(l, r, 0);
        update(d, d, total_cnt);
    }

    return 0;
}
