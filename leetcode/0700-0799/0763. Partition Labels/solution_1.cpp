// Approach: Map each value to the start of its segment.
// TC: O(nk), k - alphabet size
// SC: O(n)
class Solution {
    #define ALPHABET_LEN 26
    inline int ctoi(char c) { return c - 'a'; }
public:
    vector<int> partitionLabels(string& s) {
        int first[ALPHABET_LEN];
        memset(first, 0xFF, sizeof(first));

        int n = s.size();
        for (int i = 0; i < s.size(); ++i) {
            char j = ctoi(s[i]);
            if (first[j] == -1) 
                first[j] = i;
            else for (int k = 0; k < ALPHABET_LEN; ++k) 
                first[k] = min(first[k], first[j]);
        }

        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < n; ++i, ++cnt) {
            if (i != 0 && first[ctoi(s[i - 1])] != first[ctoi(s[i])]) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        ans.push_back(cnt);
        return ans;
    }
};