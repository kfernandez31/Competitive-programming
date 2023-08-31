// Approach: DFS.
// TC: O(mn)
// SC: O(mn)
class Solution {
    int m, n;
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if ((i < 0 || m <= i) || (j < 0 || n <= j) || grid[i][j] == '0')
            return false;
        grid[i][j] = '0';
        for (auto& [di, dj] : dirs)
            dfs(grid, i + di, j + dj);
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans += dfs(grid, i, j);
        return ans;
    }
};