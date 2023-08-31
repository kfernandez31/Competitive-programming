// Approach: Top-down DP w/memo.
// TC: O(nk), k - sum of nums
// SC: O(nk)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(), 0); 
        if (target < -max_sum || max_sum < target)
            return 0;

        unordered_map<int, unordered_map<int, int>> memo;

        function<int(int, int)> dp = [&](int i, int t) {
            if (i == n)
                return t == 0 ? 1 : 0;
            if (memo.count(i) && memo[i].count(t))
                return memo[i][t];
            int took_plus  = dp(i + 1, t - nums[i]);
            int took_minus = dp(i + 1, t + nums[i]);
            return memo[i][t] = took_plus + took_minus;
        };
        
        return dp(0, target);
    }
};