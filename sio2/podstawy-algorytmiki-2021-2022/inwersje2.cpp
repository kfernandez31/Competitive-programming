#include <bits/stdc++.h>
using namespace std;

const int maxN = 1 << 16;
int arr[maxN];
int tree[2 * maxN];
int n, k;

int f(int a, int b) {
    return a + b;
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
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += query(arr[i] + 1, n); // query for elements greater
        update(arr[i], 1 + query(arr[i], arr[i])); // update current element's occurrences      
    }
    return res;
}

void scale_input() {
    map<int, int> mappings;
    int cur = 0;
    for (int i = 0; i < n; i++) 
        mappings.insert({arr[i], 0});
    for (auto & kv : mappings) 
        mappings[kv.first] = cur++;
    for (int i = 0; i < n; i++) 
        arr[i] = mappings[arr[i]];   
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    scale_input();

    cout << solve() << "\n";

    return 0;
}