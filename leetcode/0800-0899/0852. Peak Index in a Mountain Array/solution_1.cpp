// Approach: Return the last element before the break of monotonicity.
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (arr[mid - 1] < arr[mid]) 
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }
};