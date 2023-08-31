// Approach: Convert each byte and append it to the result.
// TC: O(n)
// SC: O(n)
class Solution {
    inline char ctox(char c) {
        return c < 10 ? c + '0' : c - 10 + 'a'; 
    }
public:
    string toHex(unsigned num) {
        if (num == 0)
            return "0";
        string ans;
        for (;num; num >>= 4) 
            ans.push_back(ctox(num & 0xF));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};