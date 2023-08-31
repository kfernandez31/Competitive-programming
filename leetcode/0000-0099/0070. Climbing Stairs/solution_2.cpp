// Approach: Like solution #1, but without swapping.
// TC: O(n),
// SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int dp[3] = {1, 1};
        for (int i = 2; i <= n; ++i) 
            dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];
        return dp[n % 2];
    }
};