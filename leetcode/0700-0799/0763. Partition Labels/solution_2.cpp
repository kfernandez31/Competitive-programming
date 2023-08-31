// Approach: If encountering the last element of a segment, close it.
// TC: O(n)
// SC: O(n)
class Solution {
    #define ALPHABET_LEN 26
    inline int ctoi(char c) { return c - 'a'; }
public:
    vector<int> partitionLabels(string& s) {
        int last[ALPHABET_LEN] = {};

        int n = s.size();
        for (int i = 0; i < s.size(); ++i) 
            last[ctoi(s[i])] = i;
        
        vector<int> ans;
        int prev = -1, max_last = 0;
        for (int i = 0; i < n; ++i) {
            max_last = max(max_last, last[ctoi(s[i])]);
            if (max_last == i) {
                ans.push_back(max_last - prev);
                prev = max_last;
            }
        }

        return ans;
    }
};