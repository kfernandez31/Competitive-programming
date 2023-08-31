// Approach: Bottom-up DP.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int m = a.size(), n = b.size(); 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j) 
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        return dp[m][n];
    }
};