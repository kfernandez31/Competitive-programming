// Approach: Bottom-down DP.
// TC: O(n)
// SC: O(n)
class Solution {
    inline int ctoi(char c) { return c - '0'; } 
public:
    int numDecodings(string& s) {
        int n = s.size();

   	    vector<int> dp(n + 1);
   	    dp[0] = 1;
   	    dp[1] = s[0] != '0';

   	    for (int i = 2; i <= n; ++i) {
   	        if (s[i - 1] != '0')
   	            dp[i] += dp[i - 1]; // we could have taken a single digit before

   	        int two_digit_num = 10 * ctoi(s[i - 2]) + ctoi(s[i - 1]);
   	        if (10 <= two_digit_num && two_digit_num <= 26)
   	            dp[i] += dp[i - 2]; // we could have taken two digits before
   	    }

   	    return dp[n];
    }    
};