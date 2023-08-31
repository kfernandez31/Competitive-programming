// Approach: Bottom-up DP w/space optimization.
// TC: O(sn), s - sum of nums
// SC: O(s)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        
        int n = nums.size(), target = sum / 2;
        vector<bool> dp(target + 1, 0);
        dp[0] = true;

        for (int i = 0; i < n; ++i) 
            for (int j = target; j >= nums[i]; --j)
                if (dp[j - nums[i]])
                    dp[i] = true;
        return dp[target];
    }
};