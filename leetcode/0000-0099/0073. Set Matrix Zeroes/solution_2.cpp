// Approach: Explained below.
// TC: O(mn)
// SC: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // save the first row's state
        bool fst_col_zeros = false;
        for (int i = 0; i < m && !fst_col_zeros; ++i)
            fst_col_zeros = matrix[i][0] == 0;

        // save the first col's state
        bool fst_row_zeros = false;
        for (int j = 0; j < n && !fst_row_zeros; ++j)
            fst_row_zeros = matrix[0][j] == 0;

        // use the first cells as flags
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (matrix[i][j] == 0) 
                    matrix[i][0] = matrix[0][j] = 0;

        // wipe out rows
        for (int i = 1; i < m; ++i) 
            if (matrix[i][0] == 0) 
                fill(matrix[i].begin() + 1, matrix[i].end(), 0);

        // wipe out cols
        for (int j = 1; j < n; ++j) 
            if (matrix[0][j] == 0) 
                for (int i = 1; i < m; ++i) 
                    matrix[i][j] = 0;

        // here you stop treating the first row/col as flags 
        // they will be treated like the other rows/cols

        if (fst_col_zeros)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;

        if (fst_row_zeros)
            fill(matrix[0].begin(), matrix[0].end(), 0);
    }
};