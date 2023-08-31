// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// TC: O(n)
class Solution {
    inline bool eq(char a, char b) { return b == '.' || a == b; }
public:
    bool isMatch(string& s, string& p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1);

        for (int i = 0; i <= m; ++i) {
            bool prev = i == 1;
            // bool prev = dp[0]; // equivalent
            dp[0] = i == 0;
            for (int j = 1; j <= n; ++j) {
                bool cur = dp[j];
                if (p[j - 1] == '*') 
                    dp[j] = dp[j - 2] || (i > 0 && dp[j] && eq(s[i - 1], p[j - 2]));
                else 
                    dp[j] = i > 0 && prev && eq(s[i - 1], p[j - 1]);
                prev = cur;
            }
        }

        return dp[n];
    }
};
