// Approach: BFS.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 0)
                    q.push({i, j});
            
        while (!q.empty()) {
            auto& [i, j] = q.front(); q.pop();
            for (auto& [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (0 <= x && x < m && 0 <= y && y < n) {
                    if (grid[x][y] == INT_MAX) {
                        grid[x][y] = 1 + grid[i][j];
                        q.push({x, y});
                    }
                }
            }
        }
    }
};