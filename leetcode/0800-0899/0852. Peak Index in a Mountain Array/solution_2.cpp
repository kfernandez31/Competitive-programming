// Approach: Return the first element that breaks monotonicity.
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (arr[mid] < arr[mid + 1]) 
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
};