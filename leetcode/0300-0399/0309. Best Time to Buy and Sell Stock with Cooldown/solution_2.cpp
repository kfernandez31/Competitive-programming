// Approach: Bottom-up DP w/space optimization.
// TC: O(n)
// SC: O(1)
class Solution {
    enum state { BUY, SELL, COOL };
public:
    int maxProfit(vector<int>& pr) {
        int n = pr.size();
        if (n == 1)
            return 0;

        int dp[2][3];
        dp[1][BUY]  = -pr[0];
        dp[1][SELL] = 0;
        dp[1][COOL] = 0;

        for (int i = 1; i < n; ++i) {
            swap(dp[0], dp[1]);
            dp[1][BUY]  = max(dp[0][BUY],  dp[0][COOL] - pr[i]);  // cool down or buy
            dp[1][SELL] = max(dp[0][SELL], dp[0][BUY]  + pr[i]); // cool down or sell
            dp[1][COOL] = max(dp[0][COOL], dp[0][SELL]);        // cool down
        }
        
        return max(dp[1][SELL], dp[1][COOL]);
    }
};