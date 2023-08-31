// Approach: Like solution #2, but more concise. Matching indices and values cancel out until there's only one left (the missing one).
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n;
        for (int i = 0; i < n; ++i) 
            sum = sum ^ i ^ nums[i];
        return sum;
    }
};