// Approach: Top-down DP w/memo, but more concise. Abusing the fact that C++ strings have length n+1.
// TC: O(n)
// SC: O(n)
class Solution {
    inline int ctoi(char c) { return c - '0'; } 
public:
    int numDecodings(string& s) {
        int n = s.size();
        vector<int> memo(n, -1);

        function<int(int)> bt = [&](int i) {
            if (i == n + 1 || s[i] == '0')
                return 0;
            if (i == n)
                return 1;
            
            if (memo[i] != -1)
                return memo[i];

            int ans = bt(i + 1);
            int num = 10 * ctoi(s[i]) + ctoi(s[i + 1]);
            if (num <= 26)
                ans += bt(i + 2);
                
            return memo[i] = ans;
        };

        return bt(0);
    }
};