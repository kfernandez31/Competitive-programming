// Approach: Top-down DP w/memo.
// TC: O(n^2)
// SC: O(n^2)
class Solution {
    static constexpr int MAGIC = 25100;
    static constexpr pair<int, int> opt[] = {{100,0}, {75,25}, {50,50}, {25,75}};
public:
    double soupServings(int n) {
        if (n >= MAGIC)
            return 1;

        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));

        function<double(int, int)> dp = [&](int a, int b) {
            if (a <= 0 && b <= 0)
                return 0.5;
            if (a <= 0)
                return 1.0;
            if (b <= 0)
                return 0.0;

            if (memo[a][b] != -1)
                return memo[a][b];

            double ans = 0;
            for (auto& [da, db] : opt)
                ans += 0.25 * dp(a - da, b - db);
            return memo[a][b] = ans;
        };

        return dp(n, n);
    }
};