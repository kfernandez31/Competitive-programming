// Approach: Like solution #1, but with a lookup table.
// TC: O(n)
// SC: O(n)
class Solution {
    const char* HEX = "0123456789abcdef";
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ans;
        for (int i = 0; num && i < 8; ++i, num >>= 4) 
            ans.push_back(HEX[num & 0xF]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};