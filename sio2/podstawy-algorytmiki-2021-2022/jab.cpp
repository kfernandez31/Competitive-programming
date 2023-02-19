#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
vector<int> graph[maxN + 1];
int dist[maxN + 1];
int n;
queue<int> q;

int bfs_iter(int start) {
    q.push(start);

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == 0 /*&& next != start*/) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    dist[start] = 0; // this is to correct the fact that we visit `start` twice

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int first = bfs_iter(1);
    memset(dist, 0, (n + 1) * sizeof(int));
    int second = bfs_iter(first);
    cout << dist[second] << "\n";

    return 0;
}
