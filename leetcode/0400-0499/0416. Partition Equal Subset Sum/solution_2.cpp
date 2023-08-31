// Approach: Bottom-up DP w/space optimization.
// TC: O(sn), s - sum of nums
// SC: O(2s) = O(s)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        
        int n = nums.size(), target = sum / 2;
        vector<vector<bool>> dp(2, vector<bool>(target + 1, false));
        dp[0][0] = dp[1][0] = true;

        for (int i = 0; i < n; ++i) {
            dp[1] = dp[0];
            for (int j = nums[i]; j <= target; ++j) 
                if (dp[0][j - nums[i]])
                    dp[1][j] = true;
            dp[0] = dp[1];
        }
        return dp[1][target];
    }
};