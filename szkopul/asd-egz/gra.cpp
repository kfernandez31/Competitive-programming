#include <bits/stdc++.h>
using namespace std;

#define NC (-1)

const int maxN = 5e5;

int n, m;
vector<pair<int, int>> graph[maxN + 1];
int dist[maxN + 1][2];
int color[maxN + 1];
priority_queue<pair<int, pair<int, int>>> q; // (dist, vertex, color)

void dijkstra() {
    for (int i = 2; i <= n; i++) {
        dist[i][0] = dist[i][1] = INT_MAX;
    }
    q.push({0, {1, NC}});

    while (!q.empty()) {
        auto cur_dist = -1 * q.top().first;
        auto cur_color = q.top().second.second;
        auto cur = q.top().second.first;
        q.pop();

        if (cur_dist > dist[cur][cur_color]) {
            continue;
        }

        for (auto& v : graph[cur]) {
            auto next = v.first;
            auto next_color = v.second;

            if (next_color != cur_color) {
                if (dist[next][next_color] > cur_dist + 1) {
                    dist[next][next_color] = cur_dist + 1;
                    q.push({-1 * dist[next][next_color], {next, next_color}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        int d = min(dist[i][0], dist[i][1]);
        cout << (d != INT_MAX? d : -1) << "\n";
    }

    return 0;
}
