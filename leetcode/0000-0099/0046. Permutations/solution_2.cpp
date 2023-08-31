// Approach: Simple backtracking. Keep track of the used elements with a mask.
// TC: O((n+1)!)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> acc;
        int used_mask = 0;
        function<void()> bt = [&] {
            if (acc.size() == n) {
                ans.push_back(acc);
                return;
            }

            for (int i = 0; i < n; ++i) {
                if ((used_mask & (1 << i)) == 0) {
                    acc.push_back(nums[i]);
                    used_mask |= (1 << i);
                    bt();
                    used_mask &= ~(1 << i);
                    acc.pop_back();
                }
            }
        };

        bt();
        return ans;
    }
};