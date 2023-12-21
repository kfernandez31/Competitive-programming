// Approach: Sort the array to be able to perform two-sum.
// TC: O(nlogn+n^2) = O(n^2)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        sort(nums.begin(), nums.end());

        unordered_set<vector<int>> ans_set;
        for (int i = 0; i < n - 2; ++i) {
            if (0 < i && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target)
                    ++j;
                else if (sum > target)
                    --k;
                else {
                    ans_set.insert({nums[i], nums[j], nums[k]});
                    ++j; // --k would also work;
                }
            }
        }

        vector<vector<int>> ans_vec;
        for (auto& v : ans_set)
            ans_vec.push_back(move(v));
        return ans_vec;
    }
};