// Approach: Simple backtracking. As we can consider the same element multiple times, the next recursion level must start from the same index.
// TC: O(l*2^k), k - sum_{i = 0}^{n - 1}(target / nums[i]), l - max_i(target / nums[i])
// SC: O(l)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> acc;

        function<void(int)> bt = [&](int i) {
            if (target < 0)
                return;
            if (target == 0) { 
                ans.push_back(acc);
                return;
            }
          
            for (int j = i; j < n; ++j) {
                acc.push_back(nums[j]);
                target -= nums[j];
                bt(j);
                acc.pop_back();
                target += nums[j];
            }
        };

        bt(0);
        return ans;
    }
};