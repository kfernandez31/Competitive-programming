// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n));

        function<int(int, int)> dfs = [&](int i, int j) { 
            if (memo[i][j])
                return memo[i][j];

            int ans = 1;
            for (auto& [di, dj] : dirs) {
                int x = i + di, y = j + dj;
                if (0 <= x && x < m && 0 <= y && y < n)
                    if (grid[i][j] < grid[x][y]) 
                        ans = max(ans, 1 + dfs(x, y));
            }

            return memo[i][j] = ans;
        };

        int ans = 1;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = max(ans, dfs(i, j));
        return ans;
    }
};