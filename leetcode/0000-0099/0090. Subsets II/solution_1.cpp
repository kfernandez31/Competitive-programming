// Approach: Sort the array beforehand and then skip over a segment of the same elements, if one was chosen.
// TC: O(n*2^n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> acc;

        function<void(int)> bt = [&](int i) {
            if (i == n) {
                ans.push_back(acc);
                return;
            }

            acc.push_back(nums[i]);
            bt(i + 1);
            acc.pop_back();
            while (i + 1 < n && nums[i] == nums[i + 1]) // skip the same element
                ++i;
            bt(i + 1);
        };

        sort(nums.begin(), nums.end());
        bt(0);
        return ans;
    }
};