// Approach: Bottom-up DP.
// TC: O(nk)
// SC: O(nk)
class Solution {
public:
    int change(int k, vector<int>& coins) {
        int n = coins.size();
        int dp[n][k + 1];

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = i > 0 ? dp[i - 1][j] : 0; // copy previous combinations
                if (j - coins[i] >= 0)
                    dp[i][j] += dp[i][j - coins[i]];
            }
        }

        return dp[n - 1][k];
    }
};