#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
const int maxM = 2e6;

int set_id[maxN + 1];
int set_size[maxN + 1];
pair<int, pair<int, int>> edges[maxM + 1];
int max_on_path[maxN + 1];
vector<pair<int, int>> tree[maxN + 1];
int n, m;

int find_set(int v) {
    return (v == set_id[v])? v : (set_id[v] = find_set(set_id[v]));
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {
        if (set_size[x] < set_size[y]) {
            swap(x, y);
        }
        set_id[y] = x;
        set_size[x] += set_size[y];
    }
}

void make_set(int v) {
    set_id[v] = v;
    set_size[v] = 1;
}

void kruskal() {
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <= m; i++) {
        int w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (find_set(a) != find_set(b)) {
            union_sets(a, b);
            tree[a].push_back({w, b});
            tree[b].push_back({w, a});
        }
    }
}

void dfs(int cur, int max_w) {
    max_on_path[cur] = max_w;
    for (auto adj : tree[cur]) {
        int w = adj.first;
        int next = adj.second;
        if (max_on_path[next] == -1) {
            dfs(next, max(max_w, w));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w, {a, b}};
    }

    kruskal();

    for (int i = 1; i <= n; i++) {
        max_on_path[i] = -1;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max_on_path[i] << "\n";
    }

    return 0;
}