// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(min(m,n))
class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int m = a.size(), n = b.size(); 
        if (m < n)
            return longestCommonSubsequence(b, a);
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; ++i) {
            int prev = 0;
            for (int j = 1; j <= n; ++j) {
                int cur = dp[j];
                if (a[i - 1] == b[j - 1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                prev = cur;
            }
        }
        return dp[n];
    }
};