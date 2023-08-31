// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] || grid[m - 1][n - 1])
            return 0;

        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            dp[0] &= !grid[i][0];
            for (int j = 1; j < n; ++j) 
                if (grid[i][j])
                    dp[j] = 0;
                else
                    dp[j] += dp[j - 1];
        }
        
        return dp[n - 1];
    }
};