// Approach: Bottom-down DP w/space optimization.
// TC: O(n)
// SC: O(1)
class Solution {
    inline int ctoi(char c) { return c - '0'; } 
public:
    int numDecodings(string& s) {
        int n = s.size();

   	    int dp[3];
   	    dp[0] = 1;
   	    dp[1] = s[0] != '0';

   	    for (int i = 2; i <= n; ++i) {
   	        dp[2] = (s[i - 1] != '0') ? dp[1] : 0;

   	        int two_digit_num = 10 * ctoi(s[i - 2]) + ctoi(s[i - 1]);
   	        if (10 <= two_digit_num && two_digit_num <= 26)
   	            dp[2] += dp[0];

            dp[0] = dp[1], dp[1] = dp[2];
   	    }

   	    return dp[min(n, 2)];
    }    
};