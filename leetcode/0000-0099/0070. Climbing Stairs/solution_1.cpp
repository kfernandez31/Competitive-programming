// Approach: Standard Fibonacci.
// TC: O(n),
// SC: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int dp[3] = {1, 1};
        for (int i = 2; i <= n; ++i) {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[min(2, n - 1)];
    }
};