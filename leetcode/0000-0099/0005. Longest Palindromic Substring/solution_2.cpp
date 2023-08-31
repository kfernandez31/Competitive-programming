// Approach: Bottom-up DP w/space optimization.
// TC: O(n^2)
// SC: O(2n) = O(n)
class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        vector<vector<bool>> dp(2, vector<bool>(n));

        int ans_start = 0, ans_len = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            dp[1][i] = true;
            if (i + 1 < n) {
                dp[1][i + 1] = s[i] == s[i + 1];
                if (dp[1][i + 1] && 2 > ans_len) {
                    ans_start = i;
                    ans_len   = 2;
                }
            }
            for (int j = i + 2; j < n; ++j) {
                if (s[i] == s[j] && dp[0][j - 1]) {
                    dp[1][j] = true;
                    int len = j - i + 1;
                    if (len > ans_len) {
                        ans_start = i;
                        ans_len   = len;
                    }
                } else
                    dp[1][j] = false;
            }

            swap(dp[0], dp[1]);
        }

        return s.substr(ans_start, ans_len);
    }
};