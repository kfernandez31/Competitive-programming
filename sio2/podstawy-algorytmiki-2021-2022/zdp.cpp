#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;
int n, m;

vector<pair<int, int>> graph[maxN + 1];
long long dist[maxN + 1];
priority_queue<pair<long long, int>> pq;

void dijkstra() {
    for (int i = 2; i <= n; i++) {
        dist[i] = LLONG_MAX;
    }
    pq.push({0, 1});

    while (!pq.empty()) {
        long long w = -1 * pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (auto next : graph[v]) {
            long long dist_to_next = next.first;
            int who_next = next.second;
            long long new_dist = dist[v] + dist_to_next;

            if (new_dist < dist[who_next]) {
                dist[who_next] = new_dist;
                pq.push({-1 * dist[who_next], next.second});
            }
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

    cout << "0\n";
    for (int i = 2; i <= n; i++) {
        cout << (dist[i] != LLONG_MAX? dist[i] : -1) << "\n";
    }

    return 0;
}