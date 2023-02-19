#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n, m;
vector<int> graph[maxN + 1];
bool visited[maxN + 1];
int result = true;

void dfs_rec(int cur) {
    visited[cur] = true;

    for (auto next : graph[cur]) 
        if (!visited[next]) 
            dfs_rec(next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if (n - 1 != m) {
        result = false;
    } else {
        for (int i = 0; i < m; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        dfs_rec(1);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                result = false;
                break;
            }
        }
    }

    cout << (result? "TAK" : "NIE") << "\n";

    return 0;
}
