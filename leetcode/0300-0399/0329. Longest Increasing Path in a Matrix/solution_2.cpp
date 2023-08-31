// Approach: Treating the grid as a DAG where there is an edge u-v iff u < v.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> indeg(m, vector<int>(n));

        auto valid = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto& [di, dj] : dirs) {
                    int x = i + di, y = j + dj;
                    if (valid(x, y))
                        indeg[x][y] += (grid[i][j] < grid[x][y]);
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (indeg[i][j] == 0)
                    q.push({i, j});

        int layer = 0;
        for (; !q.empty(); ++layer) {
            int sz = q.size();
            while (sz--) {
                auto& [i, j] = q.front(); q.pop();
                for (auto& [di, dj] : dirs) {
                    int x = i + di, y = j + dj;
                    if (valid(x, y) && grid[i][j] < grid[x][y]) 
                        if (--indeg[x][y] == 0)
                            q.push({x, y});
                }
            }
        }

        return layer;
    }
};