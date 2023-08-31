// Approach: Top-down DP w/memo.
// TC: O(nk)
// SC: O(nk)
class Solution {
public:
    int change(int k, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));

        function<int(int, int)> dp = [&](int i, int amt) {
            if (i == n || amt < 0)
                return 0;
            if (amt == 0)
                return memo[i][0] = 1;
                
            if (memo[i][amt] != -1)
                return memo[i][amt];

            int include = dp(i, amt - coins[i]);
            int exclude = dp(i + 1, amt);
            return memo[i][amt] = include + exclude;
        };

        return dp(0, k);
    }
};