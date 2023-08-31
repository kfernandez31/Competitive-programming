// Approach: Flatten the matrix.
// TC: O(log(mn))
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = -1, hi = m * n;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / n][mid % n] < target)
                lo = mid;
            else 
                hi = mid;
        }
        return hi != m * n && matrix[hi / n][hi % n] == target;
    }
};