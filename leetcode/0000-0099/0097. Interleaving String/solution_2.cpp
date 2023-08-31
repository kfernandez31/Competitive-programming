// Approach: Bottom-up DP.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    bool isInterleave(string& a, string& b, string& c) {
        int m = a.size(), n = b.size();
        if (m + n != c.size())
            return false;

        bool dp[m + 1][n + 1];
        dp[0][0] = true;

        // Take only the first word
        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] && a[i - 1] == c[i - 1];

        // Take only the second word
        for (int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] && b[j - 1] == c[j - 1];

        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j) 
                dp[i][j] 
                    =  (dp[i - 1][j] && a[i - 1] == c[i + j - 1]) 
                    || (dp[i][j - 1] && b[j - 1] == c[i + j - 1]);
        return dp[m][n];
    }
};