// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(min(m,n))
class Solution {
public:
    bool isInterleave(string& a, string& b, string& c) {
        int m = a.size(), n = b.size();
        if (m + n != c.size())
            return false;
        if (m < n)
            return isInterleave(b, a, c);

        vector<bool> dp(n + 1);

        dp[0] = true;
        // Take only the second word
        for (int j = 1; j <= n && dp[j - 1]; ++j)
            dp[j] = dp[j - 1] && b[j - 1] == c[j - 1];

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && a[i - 1] == c[i - 1]; // take a character from the first word
            for (int j = 1; j <= n; ++j) 
                dp[j]
                    =  (dp[j]     && a[i - 1] == c[i + j - 1]) 
                    || (dp[j - 1] && b[j - 1] == c[i + j - 1]);
        }
        return dp[n];
    }
};