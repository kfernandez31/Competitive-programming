// Approach: Like solution #1, but perhaps more readable.
// TC: O(mn)
// SC: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);

        int left = 0, right  = n - 1;
        int top  = 0, bottom = m - 1;
        int pos = -1;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; ++j) 
                ans[++pos] = matrix[top][j];
            ++top;

            for (int i = top; i <= bottom; ++i) 
                ans[++pos] = matrix[i][right];
            --right;

            if (right < left || bottom < top) 
                break;

            for (int j = right; j >= left; --j) 
                ans[++pos] = matrix[bottom][j];
            --bottom;
            
            for (int i = bottom; i >= top; --i) 
                ans[++pos] = matrix[i][left];
            ++left;
        }
        return ans;
    }
};