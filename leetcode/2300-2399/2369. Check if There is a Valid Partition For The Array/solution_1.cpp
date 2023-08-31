// Approach: Bottom-up DP.
// TC: O(n)
// SC: O(n)
class Solution {
    bool is_2n_plus_3m(int num) {
        for (int n = 0; 2 * n <= num; ++n) 
            if ((num - 2 * n) % 3 == 0)
                return true;
        return false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if (!is_2n_plus_3m(n))
            return false;

        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                if (i + 1 < n) {
                    if (nums[i] == nums[i + 1]) 
                        dp[i + 2] = true;
                }
                if (i + 2 < n) {
                    if (nums[i]     == nums[i + 1] && nums[i + 1] == nums[i + 2]) 
                        dp[i + 3] = true;
                    if (nums[i] + 1 == nums[i + 1] && nums[i + 1] == nums[i + 2] - 1)
                        dp[i + 3] = true;   
                }
            }
        }
        return dp[n];
    }
};