// Approach: Sort the array beforehand and then skip over a segment of the same elements, if one was chosen.
// TC: O(l*2^k), k - sum_{i = 0}^{n - 1}(target / nums[i]), l - max_i(target / nums[i])
// SC: O(l)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
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

            int prev = -1;
            for (int j = i; j < n; ++j) {
                if (prev == nums[j])
                    continue;
                acc.push_back(nums[j]); target -= nums[j];
                bt(j + 1);
                acc.pop_back();         target += nums[j];
                prev = nums[i];
            }
        };

        sort(nums.begin(), nums.end());
        bt(0);
        return ans;
    }
};