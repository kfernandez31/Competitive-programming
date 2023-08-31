// Approach: Xor over indices and values.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int a = n, b = 0;
        for (int i = 0; i < n; ++i) 
            a ^= i, b ^= nums[i];
        return a ^ b;
    }
};