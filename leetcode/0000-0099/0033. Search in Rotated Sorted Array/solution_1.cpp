// Approach: Use 2-3 binary searches. First, find the index of the minimum (where there is a break of monotonicity). Then we can perform regular binary search on the two halves of the array.
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int get_min_idx(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            // consecutive mids are greater than lo UNTIL min_idx
            if (nums[lo] < nums[mid])
                lo = mid;
            else
                hi = mid;
        }

        return hi;
    }

    int binsearch(int* nums, int n, int target) {
        int lo = -1, hi = n;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target)
                lo = mid;
            else
                hi = mid;
        }
        if (hi == n || nums[hi] != target)
            return -1;
        else
            return hi;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int min_idx = get_min_idx(nums);
        int ans = binsearch(nums.data() + min_idx, n - min_idx, target);
        if (ans != -1)
            return min_idx + ans;
        else 
            return binsearch(nums.data(), min_idx, target);
        
    }
};