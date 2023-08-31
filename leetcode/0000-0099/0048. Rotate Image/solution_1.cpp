// Approach: Use a composition of two reflections.
// TC: O(mn)
// SC: O(1)
class Solution {
    void reflectAntiDiagonally(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n - 1 - i; ++j) 
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
    }
    
    void reflectHorizontally(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        reflectAntiDiagonally(matrix);
        reflectHorizontally(matrix);
    }
};