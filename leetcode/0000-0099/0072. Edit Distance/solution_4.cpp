// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(n)
class Solution {
public:
    int minDistance(string& src, string& dst) {
        int m = src.size(), n = dst.size();
        vector<int> dp(n + 1);   
        iota(dp.begin() + 1, dp.end(), 1);  
        
        for (int i = 1; i <= m; ++i) {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int cur = dp[j];
                if (src[i - 1] == dst[j - 1])
                    dp[j] = prev;
                else 
                    dp[j] = 1 + min({prev, dp[j], dp[j - 1]});
                prev = cur;
            }
        }

        return dp[n];
    }
};