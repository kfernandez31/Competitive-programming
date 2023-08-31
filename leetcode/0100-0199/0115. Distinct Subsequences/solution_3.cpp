// Approach: Bottom-up DP w/space optimization.
// TC: O(mn)
// SC: O(n)
class Solution {
public:
    int numDistinct(string& s, string& t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;

        vector<double> dp(n + 1);

        for (int i = 1; i <= m; ++i) {
            double prev = 1;
            for (int j = 1; j <= n; ++j) {
                double cur = dp[j];
                if (s[i - 1] == t[j - 1])
                    dp[j] += prev;
                prev = cur;
            }
        }

        double ans = dp[n];
        if (INT_MIN <= ans && ans <= INT_MAX) 
            return int(ans);
        else 
           return -1;
    }
};