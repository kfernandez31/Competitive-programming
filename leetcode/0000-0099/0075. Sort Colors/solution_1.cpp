// Approach: Perform a binary partition k times, each iteration creates a segment on the left of values equal to k-1.
// TC: O(kn), k - range of nums
// SC: O(n) 
class Solution {
    void partition(vector<int>& nums, function<bool(int)> p) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) 
            if (p(nums[l]))
                ++l;
            else if (!p(nums[r]))
                --r;
            else 
                swap(nums[l++], nums[r--]);
    }
public:
    void sortColors(vector<int>& nums) {
        partition(nums, [](int x) { return x == 0; });
        partition(nums, [](int x) { return x <  2; });
    }
};