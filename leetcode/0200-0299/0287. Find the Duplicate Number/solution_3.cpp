// Approach: In-place. For each number i, nums[i] stores whether it was visited in its most significant bit.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int i = abs(num);
            if (nums[i] < 0)
                return i;
            nums[i] *= -1;
        }
        return -1;
    }
};