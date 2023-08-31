// Approach: Sliding window & update the result when pushing the head.
// TC: O(k+n), k - alphabet size
// SC: O(k)
class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        bool chars[128] = {};
        int n = s.size();
        int ans = s.size() > 0;
        bool dup_char = false;

        int tail = 0, head = -1;
        while (head < n) {
            if (!dup_char) {
                if (++head < n) {
                    if (chars[s[head]])
                        dup_char = true;
                    else {
                        ans = max(ans, head - tail + 1);
                        chars[s[head]] = true;
                    }
                }
            } else {
                if (s[tail] == s[head]) // we've only got one duplicate and we're getting rid of it
                    dup_char = false;
                else
                    chars[s[tail]] = false;
                ++tail;
            }
        } 

        return ans;
    }
};