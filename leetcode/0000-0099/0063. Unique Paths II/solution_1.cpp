// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(2n) = O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] || grid[m - 1][n - 1])
            return 0;

        vector<vector<int>> dp(2, vector<int>(n));
        dp[1][0] = 1;

        for (int i = 0; i < m; ++i) {
            swap(dp[0], dp[1]);
            dp[1][0] = dp[0][0] && !grid[i][0];
            for (int j = 1; j < n; ++j) {
                if (grid[i][j])
                    dp[1][j] = 0;
                else
                    dp[1][j] = dp[0][j] + dp[1][j - 1];
            }
        }
        
        return dp[1][n - 1];
    }
};