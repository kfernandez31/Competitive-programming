// Approach: Sliding window & update the result when pushing the head.
// TC: O(kn), k - alphabet size
// SC: O(k)
class Solution {
public:
    int characterReplacement(string& s, int k) {
        unordered_map<char, int> freq;

        for (char c = 'A'; c <= 'Z'; ++c)
            freq[c] = 0;
        freq[s[0]] = 1;

        int n = s.size();
        int ans = 0;
        int tail = 0, head = 0;
        while (head < n) {
            char most_freq = 'A';
            for (char c = 'B'; c <= 'Z'; ++c)
                if (freq[c] > freq[most_freq])
                    most_freq = c;
            int others = head - tail + 1 - freq[most_freq];
            if (others <= k) {
                ans = max(ans, head - tail + 1);
                if (++head < n)
                    ++freq[s[head]];
            } else 
                --freq[s[tail++]];
        }
        return ans;
    }
};