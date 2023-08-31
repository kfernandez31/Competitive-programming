// Approach: Binary search but with a few subtleties. First, narrow down the search area by 1 from each side. If the array has been rotated less than n times, then the first element is NOT the minimum and there will be a point in the array, from which elements are less than it. If it has, then simply return the first element.
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            // this also works
            // if (nums[lo] < nums[mid])
            if (nums[0] < nums[mid])
                lo = mid;
            else
                hi = mid;
        }

        return min(nums[0], nums[hi]);
    }
};