// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    bool isMatch(string& s, string& p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        function<int(int, int)> bt = [&](int i, int j) -> int {
            if (j == n)
                return i == m;
    
            if (i < m && memo[i][j] != -1)
                return memo[i][j];

            int match = i < m && (s[i] == p[j] || p[j] == '.');

            int ans;
            if (j + 1 < n && p[j + 1] == '*') 
                ans = bt(i, j + 2) || (match && bt(i + 1, j));
            else
                ans = match && bt(i + 1, j + 1);
            
            if (i < m)
                memo[i][j] = ans;
            return ans;
        };

        return bt(0, 0);
    }
};