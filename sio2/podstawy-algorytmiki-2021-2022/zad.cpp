#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, m, q;
vector<int> graph[maxN + 1];
bool visited[maxN + 1];
int component[maxN + 1];

void dfs_rec(int cur, int comp) {
    visited[cur] = true;
    component[cur] = comp;
    for (auto next : graph[cur]) {
        if (!visited[next]) {
            dfs_rec(next, comp);
        }
    }
}

bool path_exists(int a, int b) {
    return component[a] == component[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs_rec(i, i);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (path_exists(a, b)? "T" : "N") << "\n";
    }
    
    return 0;
}
