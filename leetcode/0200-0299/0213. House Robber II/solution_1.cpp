// Approach: Pick an arbitrary point (here - the first/last one) and consider the optimal approach for the array with, and without it.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int solve(int* nums, int n) {
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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums.back();
        nums.push_back(0);
        int right_res = solve(nums.data() + 1, n - 1);
        nums[n - 1] = 0;
        int left_res = solve(nums.data(), n - 1);
        return max(left_res, right_res);
    }
};