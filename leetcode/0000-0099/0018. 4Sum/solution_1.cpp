// Approach: Backtracking with base case being two-sum. 
// TC: O(n^3) //TODO: is this not O(n^4)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4)
            return {};
        vector<vector<int>> ans;
        vector<int> acc;

        function<void(int, int, long)> kSum = [&](int k, int start, long target) {
            if (k > 2)
                for (int i = start; i < n - k + 1; ++i) {
                    if (start < i && nums[i - 1] == nums[i])
                        continue;
                    acc.push_back(nums[i]);
                    kSum(k - 1, i + 1, target - nums[i]);
                    acc.pop_back();
                }
            else {
                int l = start, r = n - 1;
                while (l < r) {
                    long sum = long(nums[l]) + long(nums[r]);
                    if (sum < target) 
                        ++l;
                    else if (sum > target)
                        --r;
                    else {
                        acc.push_back(nums[l++]); acc.push_back(nums[r--]);
                        ans.push_back(acc);
                        acc.pop_back(); acc.pop_back(); 
                        while (l < r && nums[l - 1] == nums[l])
                            ++l;
                    }
                }
            }
        };

        sort(nums.begin(), nums.end());
        kSum(4, 0, target);
        return ans;
    }
};