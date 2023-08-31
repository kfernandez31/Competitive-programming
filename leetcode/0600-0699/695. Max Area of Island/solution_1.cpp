// Approach: DFS.
// TC: O(mn)
// SC: O(mn)
class Solution {
    int m, n;
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if ((i < 0 || m <= i) || (j < 0 || n <= j) || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int ans = 1;
        for (auto& [di, dj] : dirs)
            ans += dfs(grid, i + di, j + dj);
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};