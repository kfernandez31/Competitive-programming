// Approach: Bottom-up DP.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int minDistance(string& src, string& dst) {
        int m = src.size(), n = dst.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) 
            dp[i][0] = i;
        
        for (int j = 1; j <= n; ++j) 
            dp[0][j] = j;
        
        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j) 
                if (src[i - 1] == dst[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});

        return dp[m][n];
    }
};