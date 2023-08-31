// Approach: For each number look for its complement in a map.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m[target - nums[i]])
                return {i, m[target - nums[i]] - 1};
            m[nums[i]] = i + 1;
        }
        return {};
    }
};