// Approach: BFS.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int sz = 1;
                    grid[i][j] = 0;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto& [x, y] = q.front(); q.pop();
                        for (auto& [dx, dy] : dirs) {
                            int a = x + dx;
                            int b = y + dy;
                            if ((0 <= a && a < m) && (0 <= b && b < n) && grid[a][b] == 1) {
                                ++sz;
                                grid[a][b] = 0;
                                q.push({a, b});
                            }
                        }
                    }
                    ans = max(ans, sz);
                }       
            }
        }
        return ans;
    }
};