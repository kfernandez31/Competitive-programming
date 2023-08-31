// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int m = a.size(), n = b.size(); 
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        function<int(int, int)> bt = [&](int i, int j) {
            if (i == m || j == n)
                return 0;
            if (memo[i][j] != -1)
                return memo[i][j];
            if (a[i] == b[j])
                return memo[i][j] = 1 + bt(i + 1, j + 1);
            else 
                return memo[i][j] = max(bt(i, j + 1), bt(i + 1, j));
        };

        return bt(0, 0);
    }
};