// Approach: Dijkstra. Consider shortest paths with regard to the maximum path waiting time.
// TC: O(n^2logn)
// SC: O(n^2)
class Solution {
    #define VISITED (-1)
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        grid[0][0] = VISITED;

        priority_queue<tuple<int, int, int>> pq;
        pq.push({-grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto& [h, i, j] = pq.top(); pq.pop();
            if (i == n - 1 && j == n - 1)
                return -h;

            for (auto& [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (0 <= x && x < n && 0 <= y && y < n) {
                    if (grid[x][y] != VISITED) {
                        pq.push({-max(-h, grid[x][y]), x, y});   
                        grid[x][y] = VISITED;
                    }
                }
            }
        }

        return 42;
    }
};