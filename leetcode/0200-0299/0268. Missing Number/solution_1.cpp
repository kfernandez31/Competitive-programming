// Approach: Subtract from the expected sum.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        for (int num : nums) 
            sum -= num;
        return sum;
    }
};