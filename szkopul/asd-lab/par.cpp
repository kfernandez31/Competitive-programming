#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;

constexpr int my_log2(int val) {
    int res = 0;
    while (val > 1) {
        val >>= 1;
        res++;
    }
    return res;
}

int depth[maxN + 1];
int jmp[maxN + 1][my_log2(maxN) + 1];
pair<int, int> far[maxN + 1];
pair<int, int> fardown[maxN + 1];
pair<int, int> farup[maxN + 1];
int left_child[maxN + 1];
int right_child[maxN + 1];
int parent[maxN + 1];
int n, m;

inline int sibling(int v) {
    if (left_child[parent[v]] == v) 
        return right_child[parent[v]];
    if (right_child[parent[v]] == v) 
        return left_child[parent[v]];
    return -1;
}

void get_depth(int v, int d) {
    depth[v] = d;

    int left  = left_child[v];
    if (left != -1) {
        get_depth(left, 1 + d);
    }

    int right = right_child[v];
    if (right != -1) {
        get_depth(right, 1 + d);
    }
}

void get_jumps() {
    int log = my_log2(n);
    for (int i = 0; i <= log; i++) {
        for (int v = 1; v <= n; v++) {
            if (i == 0) {
                jmp[v][0] = parent[v];
            } else {
                jmp[v][i] = jmp[jmp[v][i - 1]][i - 1];
            }
        }
    }
}

void get_fardown(int v) {
    vector<pair<int, int>> res;
    res.reserve(3);
    res.push_back({0, v});

    int left = left_child[v];
    if (left != -1) {
        get_fardown(left);
        auto [d, u] = fardown[left];
        res.push_back({d + 1, u});
    }

    int right = right_child[v];
    if (right != -1) {
        get_fardown(right);
        auto [d, u] = fardown[right];
        res.push_back({d + 1, u});
    }

    sort(res.begin(), res.end());
    fardown[v] = res[res.size() - 1];
}

void get_farup(int v) {
    vector<pair<int, int>> res;
    res.reserve(3);
    res.push_back({0, v});

    if (v != 1) {
        auto [d, u] = farup[parent[v]];
        res.push_back({d + 1, u});

        int sib = sibling(v);
        if (sib != -1) {
            auto [d, u] = fardown[sib];
            res.push_back({d + 2, u});
        }
    }

    sort(res.begin(), res.end());
    farup[v] = res[res.size() - 1];

    int left  = left_child[v];
    if (left != -1) {
        get_farup(left);
    }
    
    int right = right_child[v];
    if (right != -1) {
        get_farup(right);
    }
}

void get_far() {
    get_fardown(1);
    get_farup(1);
    for (int v = 1; v <= n; v++) {
        far[v] = max(farup[v], fardown[v]);
    }
}

int get_ancestor(int v, int dist) {
    int res = v, i = my_log2(n);
    while (dist > 0) {
        if ((1 << i) > dist) {
            i--;
        } else {
            res = jmp[res][i];
            dist -= (1 << i);
        }
    }
    return res;
}

int get_lca(int u, int v) {
    int du = depth[u], dv = depth[v];
    if (du < dv) {
        return get_lca(u, get_ancestor(v, dv - du));
    } else if (du > dv) {
        return get_lca(get_ancestor(u, du - dv), v);
    }

    // assert(du == dv);

    if (u == v) {
        return u;
    }

    for (int i = my_log2(n); i >= 0; i--) {
        if (jmp[u][i] != jmp[v][i]) {
            u = jmp[u][i];
            v = jmp[v][i];
        }
    }

    // assert(parent[u] = parent[v]);

    return parent[u];
}

int solve(int u, int d) {
    auto [d_max, v] = far[u];
    if (d > d_max) {
        return -1;
    }
    int lca = get_lca(u, v);
    int du = depth[u] - depth[lca];
    int dv = depth[v] - depth[lca];

    // assert(du + dv == d_max)
    
    if (d <= du) {
        return get_ancestor(u, d);
    } else {
        return get_ancestor(v, dv - (d - du));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        left_child[i] = a;
        right_child[i] = b;
        if (a != -1) {
            parent[a] = i;
        }
        if (b != -1) {
            parent[b] = i;
        }
    }

    get_depth(1, 0);
    get_jumps();
    get_far();

    cin >> m;
    while (m--) {
        int v, d;
        cin >> v >> d;
        cout << solve(v, d) << "\n";
    }

    return 0;
}
