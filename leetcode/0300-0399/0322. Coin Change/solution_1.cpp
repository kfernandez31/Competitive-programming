// Approach: Bottom-up DP.
// TC: O(n*amount)
// SC: O(amount)
class Solution {
    static constexpr int INFTY = 1e4 + 1;
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int dp[amount + 1];
        dp[0] = 0;
        for (int amt = 1; amt <= amount; ++amt) {
            dp[amt] = INFTY;
            for (int c : coins)
                if (amt - c >= 0) 
                    dp[amt] = min(dp[amt], 1 + dp[amt - c]);                
                else
                    break;
        }
        return dp[amount] == INFTY ? -1 : dp[amount];
    }
};