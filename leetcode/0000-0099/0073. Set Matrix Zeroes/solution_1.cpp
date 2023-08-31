// Approach: Remember each row and column in a  
// TC: O(mn)
// SC: O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (matrix[i][j] == 0) 
                    rows.insert(i), cols.insert(j);
                
        for (int i : rows)
            fill(matrix[i].begin(), matrix[i].end(), 0);
        for (int i = 0; i < m; ++i)
            for (int j : cols)
                matrix[i][j] = 0;
    }
};