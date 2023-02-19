#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
const int maxM = 2e6;

int set_id[maxN + 1];
int set_size[maxN + 1];
int num_sets;
pair<int, pair<int, int>> edges[maxM + 1];
int lightest_edge[maxN + 1];
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
        num_sets--;
    }
}

void make_set(int v) {
    set_id[v] = v;
    set_size[v] = 1;
}

void boruvka() {
    int prev_num_sets = -1;
    int it = 0;
    while (prev_num_sets != num_sets) {            
        memset(lightest_edge, 0, sizeof(lightest_edge));
        prev_num_sets = num_sets;

        for (int i = 1; i <= m; i++) {
            int set_a = find_set(edges[i].second.first);
            int set_b = find_set(edges[i].second.second);
            if (set_a != set_b) {
                if (!lightest_edge[set_a] || edges[i] < edges[lightest_edge[set_a]]) {
                    lightest_edge[set_a] = i;
                }
                if (!lightest_edge[set_b] || edges[i] < edges[lightest_edge[set_b]]) {
                    lightest_edge[set_b] = i;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (lightest_edge[i]) {
                auto e = edges[lightest_edge[i]];
                int a = e.second.first, a_set = find_set(a);
                int b = e.second.second, b_set = find_set(b);
                if (a_set != b_set) {
                    union_sets(a, b);
                    tree[a].push_back({e.first, b});
                    tree[b].push_back({e.first, a});                
                }
            }
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

    num_sets = n;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w, {a, b}};
    }

    boruvka();

    for (int i = 1; i <= n; i++) {
        max_on_path[i] = -1;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max_on_path[i] << "\n";
    }

    return 0;
}