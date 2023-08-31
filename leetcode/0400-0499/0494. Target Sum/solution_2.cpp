// Approach: Bottom-up DP.
// TC: O(nk), k - sum of nums
// SC: O(nk)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(), 0); 
        if (target < -max_sum || max_sum < target)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * max_sum + 1));
        dp[0][max_sum + nums[0]] += 1;
        dp[0][max_sum - nums[0]] += 1;

        for (int i = 1; i < n; ++i) {
            for (int j = -max_sum; j <= max_sum; ++j) {
                if (j - nums[i] >= -max_sum)
                    dp[i][max_sum + j] += dp[i - 1][max_sum + j - nums[i]];
                if (j + nums[i] <= max_sum)
                    dp[i][max_sum + j] += dp[i - 1][max_sum + j + nums[i]];
            }
        }

        return dp[n - 1][max_sum + target];
    }
};