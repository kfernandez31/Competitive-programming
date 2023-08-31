// Approach: Top-down DP w/memo.
// TC: O(sn), s - sum of nums
// SC: O(sn)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;

        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(sum / 2 + 1, -1));

        function<int(int, int)> bt = [&](int i, int target) {
            if (i == n)
                return int(target == 0);
            if (target < 0)
                return 0;
            if (target == 0)
                return 1;
            if (memo[i][target] != -1)
                return memo[i][target];
            
            return memo[i][target] 
                = bt(i + 1, target - nums[i])
                | bt(i + 1, target);
        };

        return bt(0, sum / 2);
    }
};