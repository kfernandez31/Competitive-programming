// Approach: Iterate over all masks, each mask determines a subset.
// TC: O(2^n)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset_cnt = 1 << n;
        vector<vector<int>> ans(subset_cnt);
        for (int mask = 0; mask < subset_cnt; ++mask) 
            for (int pos = 0; pos < n; ++pos)
                if (mask & (1 << pos))
                    ans[mask].push_back(nums[pos]);
        return ans;
    }
};