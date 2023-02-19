#include <bits/stdc++.h>
using namespace std;

#define DIRS 4

const int maxH = 1e3;
const int maxW = 1e3;
bool graph[maxH][maxW]; // `true` means an obstacle
bool visited[maxH][maxW];
int steps[maxH][maxW];
int w, h;
int startX, startY;
int endX, endY;
int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<pair<int, int>> q;

bool is_legal_coord(int x, int y) {
    return 
        (0 <= x && x < w) && 
        (0 <= y && y < h) && 
        !graph[x][y];
}

void bfs_iter() {
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    steps[endX][endY] = -1;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        if (cur_x == endX && cur_y == endY) {
            break;
        }

        for (int i = 0; i < DIRS; i++) {
            int new_x = cur_x + dxy[i][0];
            int new_y = cur_y + dxy[i][1];
            if (is_legal_coord(new_x, new_y) && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                steps[new_x][new_y] = steps[cur_x][cur_y] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                graph[j][i] = true;
            } else if (c == 'P') {
                startX = j;
                startY = i;
            } else if (c == 'W') {
                endX = j;
                endY = i;
            }
        }
    }

    bfs_iter();
    int result = steps[endX][endY];

    if (result == -1) {
        cout << "NIE";
    } else {
        cout << result;
    }
    cout << "\n";

    return 0;
}
