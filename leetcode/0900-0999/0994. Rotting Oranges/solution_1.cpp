// Approach: BFS from each rotting orange. Record the last rotting time when entering a fresh cell.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 2)
                    q.push({0, i, j});

        int ans = 0;
        while (!q.empty()) {
            auto& [t, i, j] = q.front(); q.pop();

            if (grid[i][j] != 2)
                ans = t;
            grid[i][j] = 2;

            for (auto& [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if ((0 <= x && x < m) && (0 <= y && y < n))
                    if (grid[x][y] == 1)
                        q.push({t + 1, x, y});
            }
        }

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == 1)
                    return -1;
        return ans;
    }
};