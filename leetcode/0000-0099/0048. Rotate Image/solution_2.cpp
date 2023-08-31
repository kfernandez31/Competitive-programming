// Approach: Like solution #2, just symmetrical.
// TC: O(mn)
// SC: O(1)
class Solution {
    // otherwise known as transpose()
    void reflectDiagonally(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void reflectVertically(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        reflectDiagonally(matrix);
        reflectVertically(matrix);
    }
};
