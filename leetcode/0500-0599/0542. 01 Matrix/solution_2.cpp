// Approach: Bottom-up dynamic programming, in-place.
// TC: O(mn)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& dp) {
        int m = dp.size(), n = dp[0].size(), INF = m + n;

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (dp[i][j] != 0)
                    dp[i][j] = min(
                        0 <= i - 1 ? 1 + dp[i - 1][j] : INF,
                        0 <= j - 1 ? 1 + dp[i][j - 1] : INF
                    );
            
        for (int i = m - 1; i >= 0; --i) 
            for (int j = n - 1; j >= 0; --j) 
                if (dp[i][j] != 0)
                    dp[i][j] = min({
                        dp[i][j],
                        i + 1 < m ? 1 + dp[i + 1][j] : INF,
                        j + 1 < n ? 1 + dp[i][j + 1] : INF
                    });      
        return dp;
    }
};