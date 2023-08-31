// Approach: Maintain a shrinking window.
// TC: O(mn)
// SC: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);

        int pos = -1;
        for (int layer = 0; 2 * layer < m && 2 * layer < n; ++layer) {
            for (int j = layer; j < n - layer; ++j)     // upper row 
                ans[++pos] = matrix[layer][j];

            for (int i = layer + 1; i < m - layer; ++i) // right column (without the top el.)
                ans[++pos] = matrix[i][n - layer - 1];

            if (2 * layer >= m - 1 || 2 * layer >= n - 1) 
                break;
        
            for (int j = n - layer - 2; j >= layer; --j) // lower row (without the rightmost el.)
                ans[++pos] = matrix[m - layer - 1][j];

            for (int i = m - layer - 2; i > layer; --i) // left column (without the top and bottom el.)
                ans[++pos] = matrix[i][layer];
        }
        return ans;
    }
};