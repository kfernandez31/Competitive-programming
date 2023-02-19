#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;
int n, m;

vector<pair<int, int>> graph[maxN + 1];
int dist[maxN + 1];
priority_queue<pair<int, int>> pq;
vector<int> parents[maxN + 1];
bool visited[maxN + 1];

void dijkstra() {
    for (int i = 2; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    pq.push({0, 1});

    while (!pq.empty()) {
        int w = -1 * pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (auto next : graph[v]) {
            int dist_to_next = next.first;
            int who_next = next.second;
            int new_dist = dist[v] + dist_to_next;

            if (new_dist < dist[who_next]) {
                dist[who_next] = new_dist;
                parents[who_next] = {v};
                pq.push({-1 * dist[who_next], next.second});
            } else if (new_dist == dist[who_next]) {
                parents[who_next].push_back(v);
            }
        }
    }
}

void dfs(int cur) {
    visited[cur] = true;
    for (int next : parents[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    dijkstra(); 
    dfs(n);

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}