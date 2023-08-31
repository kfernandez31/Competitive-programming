// Approach: Try to sell the minimum of a prefix on that prefix.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_buy = 1e4 + 1;
        for (int price : prices) {
            ans     = max(ans, price - min_buy);
            min_buy = min(min_buy, price);
        }
        return ans;
    }
};