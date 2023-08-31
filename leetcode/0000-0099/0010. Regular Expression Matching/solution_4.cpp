// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// TC: O(2n) = O(n)
class Solution {
    inline bool eq(char a, char b) { return b == '.' || a == b; }
public:
    bool isMatch(string& s, string& p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(2, vector<bool>(n + 1));

        dp[1][0] = true;
        for (int i = 0; i <= m; ++i) {
            swap(dp[0], dp[1]);
            dp[1][0] = i == 0;
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') 
                    dp[1][j] = dp[1][j - 2] || (i > 0 && dp[0][j] && eq(s[i - 1], p[j - 2]));
                else 
                    dp[1][j] = i > 0 && dp[0][j - 1] && eq(s[i - 1], p[j - 1]);
            }
        }

        return dp[1][n];
    }
};