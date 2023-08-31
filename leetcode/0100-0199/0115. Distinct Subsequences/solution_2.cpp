// Approach: Bottom-up DP.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int numDistinct(string& s, string& t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;

        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        double ans = dp[m][n];
        if (INT_MIN <= ans && ans <= INT_MAX) 
            return static_cast<int>(ans);
        else 
           return -1;
    }
};