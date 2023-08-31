// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(2n) = O(n)
class Solution {
public:
    int minDistance(string& src, string& dst) {
        int m = src.size(), n = dst.size();
        vector<vector<int>> dp(2, vector<int>(n + 1));        
        for (int j = 1; j <= n; ++j) 
            dp[1][j] = j;

        for (int i = 1; i <= m; ++i) {
            swap(dp[0], dp[1]);
            dp[1][0] = i;
            for (int j = 1; j <= n; ++j) 
                if (src[i - 1] == dst[j - 1])
                    dp[1][j] = dp[0][j - 1];
                else 
                    dp[1][j] = 1 + min({dp[0][j - 1], dp[0][j], dp[1][j - 1]});
        }

        return dp[1][n];
    }
};