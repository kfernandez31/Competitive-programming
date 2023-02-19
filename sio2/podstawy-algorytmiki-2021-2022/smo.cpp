#include <bits/stdc++.h>
using namespace std;

#define DIRS 4

const int maxN = 1e3;
const int maxM = 1e3;
int time_visited[maxN][maxM];
int n, m, t;
int num_burnt;
int dxy[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<pair<int, int>> q;

bool is_legal_coord(int x, int y) {
    return 
        (0 <= x && x < n) && 
        (0 <= y && y < m);
}

void bfs_iter() {
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for (int i = 0; i < DIRS; i++) {
            int new_x = cur_x + dxy[i][0];
            int new_y = cur_y + dxy[i][1];
            if (is_legal_coord(new_x, new_y) && time_visited[new_x][new_y] == -1) {
                int new_time = time_visited[cur_x][cur_y] + 1;
                if (new_time <= t) {
                    num_burnt++;
                }
                time_visited[new_x][new_y] = new_time;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'x') {
                time_visited[i][j] = 0;
                q.push({i, j});
                num_burnt++;
            } else {
                time_visited[i][j] = -1;
            }
        }
    }

    bfs_iter();

    cout << num_burnt << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (time_visited[i][j] <= t) {
                 cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
    cout << "\n";

    return 0;
}
