// Approach: Treat the matrix like a BST.
// TC: O(log(mn))
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j > -1) {
            int cur = matrix[i][j];
            if (cur == target) 
                return true;
            else if (cur < target) 
                ++i;
            else 
                --j;
        }
        
        return false;
    }
};