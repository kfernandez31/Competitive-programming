// Approach: Like solution #2, but cuts the last bit without branching.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) 
            dp[i] = 1 + dp[i & (i - 1)];
        return dp;
    }
};