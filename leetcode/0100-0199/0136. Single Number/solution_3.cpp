// Approach: Like solution #2 but with STL.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) { return acc ^ v; });
    }
};