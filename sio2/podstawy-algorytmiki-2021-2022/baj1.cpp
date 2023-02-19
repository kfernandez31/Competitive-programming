#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5;
const int maxM = 3e5;

int set_id[maxN + 1];
int set_size[maxN + 1];
bool can_be_included[maxM + 1];
int n, m;

struct edge {
    int u, v, weight, id;
    bool operator<(const edge& other) const {
        return weight < other.weight;
    }
    bool operator>(const edge& other) const {
        return weight > other.weight;
    }
    bool operator==(const edge& other) const {
        return weight == other.weight;
    }
} edges[maxM + 1];

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
    for (int i = 1; i <= m; i++) {
        if (edges[i - 1] < edges[i]) {
            for (int j = i; j <= m && edges[j] == edges[i]; j++) {
                can_be_included[edges[j].id] = (find_set(edges[j].u) != find_set(edges[j].v));
            }
        }
        if (find_set(edges[i].u) != find_set(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = edge { .u = a, .v = b, .weight = w, .id = i };
    }
    sort(edges + 1, edges + m + 1);

    kruskal();

    for (int i = 1; i <= m; i++) {
        cout << (can_be_included[i]? "TAK\n" : "NIE\n");
    }

    return 0;
}