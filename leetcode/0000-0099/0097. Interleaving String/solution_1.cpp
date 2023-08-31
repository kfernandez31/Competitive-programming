// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    bool isInterleave(string& a, string& b, string& c) {
        int m = a.size(), n = b.size();
        if (m + n != c.size())
            return false;

        vector<vector<int>> memo(m, vector<int>(n, -1));

        function<int(int, int)> bt = [&](int i, int j) {
            if (i == m && j == n) 
                return 1;

            if (i < m && j < n && memo[i][j] != -1)
                return memo[i][j];

            int ans  
                = (i < m && a[i] == c[i + j] && bt(i + 1, j))
                | (j < n && b[j] == c[i + j] && bt(i, j + 1));

            if (i < m && j < n)
                memo[i][j] = ans;
            return ans;
        };

        return bt(0, 0);
    }
};