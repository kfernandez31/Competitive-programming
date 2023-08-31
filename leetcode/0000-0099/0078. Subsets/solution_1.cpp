// Approach: Simple backtracking.
// TC: O(n*2^n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> acc;

        function<void(int)> bt = [&](int i) {
            if (i == n) {
                ans.push_back(acc);
                return;
            }
            acc.push_back(nums[i]); // include
            bt(i + 1);
            acc.pop_back();         // exclude
            bt(i + 1);
        };

        bt(0);
        return ans;
    }
};