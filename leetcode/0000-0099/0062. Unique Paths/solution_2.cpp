// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(2n) = O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2);
        dp[0] = vector(n + 1, 1);
        dp[1] = vector(n + 1, 0);
        dp[0][0] = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= n; ++j) 
                dp[1][j] = dp[0][j] + dp[1][j - 1];
            swap(dp[0], dp[1]);
        }
        return dp[0][n];
    }
};