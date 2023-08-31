// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(2n) = O(n)
class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int m = a.size(), n = b.size(); 
        vector<vector<int>> dp(2, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            swap(dp[0], dp[1]);
            for (int j = 1; j <= n; ++j) 
                if (a[i - 1] == b[j - 1])
                    dp[1][j] = 1 + dp[0][j - 1];
                else
                    dp[1][j] = max(dp[1][j - 1], dp[0][j]);
        }
        return dp[1][n];
    }
};