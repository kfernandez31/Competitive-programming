// Approach: Like solution #1, but memory-optimized.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        int dp[2][2];
        dp[0][false] = 0;
        dp[0][true] = nums[0];
        for (int i = 1; i <= n; ++i) {
            dp[1][true]  = dp[0][false] + nums[i];
            dp[1][false] = max(dp[0][false], dp[0][true]);
            dp[0][true]  = dp[1][true];
            dp[0][false] = dp[1][false];
        }   
        return dp[1][false];
    }
};