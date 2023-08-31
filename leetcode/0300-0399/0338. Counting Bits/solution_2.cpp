// Approach: DP. Each even n is n/2 extended with a 0, and each odd n is n-1 extended with a 1. 
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (i & 1)
                dp[i] = dp[i - 1] + 1;
            else 
                dp[i] = dp[i >> 1];
        }
        return dp;
    }
};