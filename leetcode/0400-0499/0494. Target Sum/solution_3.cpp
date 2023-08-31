// Approach: Bottom-up DP w/space optimization.
// TC: O(nk), k - sum of nums
// SC: O(2k) = O(k)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(), 0); 
        if (target < -max_sum || max_sum < target)
            return 0;

        vector<vector<int>> dp(2, vector<int>(2 * max_sum + 1));
        dp[1][max_sum + nums[0]] += 1;
        dp[1][max_sum - nums[0]] += 1;

        for (int i = 1; i < nums.size(); ++i) {
            swap(dp[0], dp[1]);
            for (int j = 0; j <= 2 * max_sum; ++j) {
                dp[1][j] = 0;
                if (j - nums[i] >= 0)
                    dp[1][j] += dp[0][j - nums[i]];
                if (j + nums[i] <= 2 * max_sum)
                    dp[1][j] += dp[0][j + nums[i]];
            }
        }

        return dp[1][max_sum + target];
    }
};