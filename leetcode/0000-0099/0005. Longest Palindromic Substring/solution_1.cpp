// Approach: Bottom-up DP.
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        int ans_start = 0, ans_len = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            if (i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1];
                if (dp[i][i + 1] && 2 > ans_len) {
                    ans_start = i;
                    ans_len   = 2;
                }
            }
            for (int j = i + 2; j < n; ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    int len = j - i + 1;
                    if (len > ans_len) {
                        ans_start = i;
                        ans_len   = len;
                    }
                }
            }
        }

        return s.substr(ans_start, ans_len);
    }
};