#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
const int maxM = 2e6;

priority_queue<pair<int, int>> pq;
bool visited[maxN + 1];
int key[maxN + 1];
vector<pair<int, int>> graph[maxN + 1];
int lightest_edge[maxN + 1];
int max_on_path[maxN + 1];
vector<pair<int, int>> tree[maxN + 1];
int n, m;

void jarnik() {
    for (int i = 2; i <= n; i++) {
        key[i] = INT_MAX;
    }
    
    pq.push({0, 1});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (!visited[cur]) {
            visited[cur] = true;
            for (auto adj : graph[cur]) {
                int w = adj.first;
                int next = adj.second;

                if (!visited[next] && key[next] > w) {
                    key[next] = w;
                    pq.push({-1 * w, next});
                    tree[cur].push_back({w, next});
                    tree[next].push_back({w, cur});     
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

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    jarnik();

    for (int i = 1; i <= n; i++) {
        max_on_path[i] = -1;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max_on_path[i] << "\n";
    }

    return 0;
}