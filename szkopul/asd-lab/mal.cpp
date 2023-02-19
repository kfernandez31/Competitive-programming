#include <bits/stdc++.h>
using namespace std;

#define NEUTRAL_ELM 0
#define NO_OP (-1)

const int maxN = 1 << 20;

bool arr[maxN];
int tree[2 * maxN];
int lazy[2 * maxN];
int n, m;

inline int len(int a, int b) {
    return b - a + 1;
}

void push(int v, int a, int b) {
    int l = 2 * v, r = 2 * v + 1;
    if (lazy[v] != NO_OP) {
        tree[l] = lazy[v] * len(a, b) / 2;
        tree[r] = lazy[v] * len(a, b) / 2;

        lazy[l] = lazy[v];
        lazy[r] = lazy[v];

        lazy[v] = NO_OP;
    }
}

void update(int v, int a, int b, int q1, int q2, bool color) {
    if (q2 < a || b < q1) {
        return;
    }  
    if (q1 <= a && b <= q2) {
        tree[v] = color * len(a, b);
        lazy[v] = color;
        return;
    } 
    push(v, a, b);
    int l = 2 * v, r = 2 * v + 1, mid = (a + b) / 2;
    update(l, a, mid, q1, q2, color);
    update(r, mid + 1, b, q1, q2, color);
    tree[v] = tree[l] + tree[r];
}

void update(int q1, int q2, bool color) {
    update(1, 1, maxN, q1, q2, color);
}

// int query(int v, int a, int b, int q1, int q2) {
//     if (q2 < a || b < q1) {
//         return NEUTRAL_ELM;
//     } 
//     if (q1 <= a && b <= q2) {
//         return tree[v];
//     }
//     push(v, a, b);
//     int l = 2 * v, r = 2 * v + 1, mid = (a + b) / 2;
//     int left_res  = query(l, a, mid, q1, q2);
//     int right_res = query(r, mid + 1, b, q1, q2);
//     return left_res + right_res;
// }

// int query(int q1, int q2) {
//     return query(1, 1, maxN, q1, q2);
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        bool color = c == 'B';
        update(a, b, color);
        cout << tree[1] << "\n";
    }

    return 0;
}
