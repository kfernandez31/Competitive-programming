// Approach: Sort, then use the two-pointer approach.
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = {nums[i], i};
        sort(v.begin(), v.end());

        int l = 0, r = n - 1;
        while (l < r) {
            int sum = v[l].first + v[r].first;
            if (sum < target)
                ++l;
            else if (sum > target)
                --r;
            else
                return {v[l].second, v[r].second};
        }
        return {};
    }
};