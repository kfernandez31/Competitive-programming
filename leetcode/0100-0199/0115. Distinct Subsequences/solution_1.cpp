// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int numDistinct(string& s, string& t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;

        vector<vector<double>> memo(m, vector<double>(n, -1));

        function<double(int, int)> bt = [&](int i, int j) {
            if (j == n) return 1.0;
            if (i == m) return 0.0;

            if (memo[i][j] != -1)
                return memo[i][j];

            if (s[i] == t[j])
                return memo[i][j] = bt(i + 1, j) + bt(i + 1, j + 1);
            else 
                return memo[i][j] = bt(i + 1, j);
        };

        double ans = bt(0, 0);
        if (INT_MIN <= ans && ans <= INT_MAX) 
            return int(ans);
        else 
           return -1;
    }
};