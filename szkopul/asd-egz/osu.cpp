#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;

const int maxN = 1e3;
const int maxM = 1e3;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
bool graph[maxN][maxM];
int dist[maxN][maxM];
point a, b;
deque<pair<int, point>> q;

int bfs01() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    q.push_front({0, a});
    dist[a.first][a.second] = 0;

    while (!q.empty()) {
        auto cur_dist = q.back().first;
        auto x = q.back().second.first;
        auto y = q.back().second.second;
        q.pop_back();

        if (dist[x][y] < cur_dist) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (0 <= new_x && new_x <= n-1) {
                if (0 <= new_y && new_y <= m-1) {
                    if (dist[new_x][new_y] > cur_dist + graph[new_x][new_y]) {
                        dist[new_x][new_y] = cur_dist + graph[new_x][new_y];
                        if (graph[new_x][new_y] == 1) {
                            q.push_front({dist[new_x][new_y], {new_x, new_y}});
                        } else {
                            q.push_back({dist[new_x][new_y], {new_x, new_y}});
                        }
                    }
                }
            }
        }
    }

    return dist[b.first][b.second];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            graph[i][j] = (c == '#');
            if (c == 'A') {
                a = {i, j}; 
            } else if (c == 'B') {
                b = {i, j};     
            }
        }
    }

    cout << bfs01() << "\n";

    return 0;
}
