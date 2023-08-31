// Approach: Top-down DP w/memo.
// TC: O(n)
// SC: O(3n) = O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> memo_bought(n, -1), memo_sold(n, -1), memo_cool(n, -1);

        function<int(int, bool, bool)> dp = [&](int i, bool bought, bool sold) {
            if (i == n)
                return 0;

            if (bought) {
                if (memo_bought[i] != -1)
                    return memo_bought[i];
                int sell = dp(i + 1, false, true) + prices[i];
                int cool = dp(i + 1, true, false);
                return memo_bought[i] = max(sell, cool);
            } else if (!sold) {
                if (memo_cool[i] != -1)
                    return memo_cool[i];
                int buy =  dp(i + 1, true, false) - prices[i];
                int cool = dp(i + 1, false, false);
                return memo_cool[i] = max(buy, cool);
            } else {
                if (memo_sold[i] != -1)
                    return memo_sold[i];
                int cool = dp(i + 1, false, false);
                return memo_sold[i] = cool;
            }
        };

        return dp(0, false, false);
    }
};