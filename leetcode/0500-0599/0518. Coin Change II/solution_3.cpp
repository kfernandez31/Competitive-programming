// Approach: Bottom-up DP w/space optimization.
// TC: O(nk)
// SC: O(k)
class Solution {
public:
    int change(int k, vector<int>& coins) {
        vector<int> dp(k + 1);
        dp[0] = 1;
        for (int c : coins)
            for (int amt = 1; amt <= k; ++amt) 
                if (0 <= amt - c)
                    dp[amt] += dp[amt - c];
        return dp[k];
    }
};