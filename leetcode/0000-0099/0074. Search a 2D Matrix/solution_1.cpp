// Approach: Two binary searches - one row-wise, the other column-wise.
// TC: O(log(mn))
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    
        int m = matrix.size(), n = matrix[0].size();

        // row-wise search
        int lo = -1, hi = m;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] <= target)
                lo = mid;
            else
                hi = mid;
        }

        if (lo == -1)
            return false;

        auto& row = matrix[lo];
        // column-wise search
        lo = -1, hi = n;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (row[mid] < target)
                lo = mid;
            else
                hi = mid;
        }

        return hi != n && row[hi] == target;
    }
};