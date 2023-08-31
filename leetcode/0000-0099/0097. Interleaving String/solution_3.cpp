// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(2m) = O(n)
class Solution {
public:
    bool isInterleave(string& a, string& b, string& c) {
        int m = a.size(), n = b.size();
        if (m + n != c.size())
            return false;

        vector<vector<bool>>dp(2, vector<bool>(n + 1));
        dp[1][0] = true;
        // Take only the second word
        for (int j = 1; j <= n && dp[1][j - 1]; ++j)
            dp[1][j] = dp[1][j - 1] && b[j - 1] == c[j - 1];

        for (int i = 1; i <= m; ++i) {
            swap(dp[0], dp[1]);
            dp[1][0] = dp[0][0] && a[i - 1] == c[i - 1]; // take a character from the first word
            for (int j = 1; j <= n; ++j) 
                dp[1][j] 
                    =  (dp[0][j]     && a[i - 1] == c[i + j - 1]) 
                    || (dp[1][j - 1] && b[j - 1] == c[i + j - 1]);
        }
        return dp[1][n];
    }
};