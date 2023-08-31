// Approach: Top-down DP w/memo.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int numDecodings(string& s) {
        if (s[0] == '0' || s.find("00") != string::npos)
            return 0;

        int n = s.size();
        vector<int> memo(n, -1);

        function<int(int)> bt = [&](int i) {
            if (i == n) 
                return 1;
            if (s[i] == '0')
                return 0;

            if (memo[i] != -1) 
                return memo[i];
            
            int ans = 0;
            if (i <= n - 2 && (s[i] == '1' || (s[i] == '2' && '0' <= s[i + 1] && s[i + 1] <= '6')))
                ans += bt(i + 2);
            if (i <= n - 1 && s[i + 1] != '0')
                ans += bt(i + 1);

            return memo[i] = ans;
        };

        return bt(0);
    }
};