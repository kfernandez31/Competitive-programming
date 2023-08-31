// Approach: STL, introselect.
// TC: O(n) avg case, O(n^2) worst case
// SC: O(logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};