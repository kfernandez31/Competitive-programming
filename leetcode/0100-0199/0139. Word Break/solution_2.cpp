// Approach: Top-down DP w/memo.
// TC: O(nlk), l - avg. word length, k - |word dict| 
// SC: O(n)
class Solution {
public:
    bool wordBreak(string& s, vector<string>& word_dict) {
        int n = s.size();
        
        int min_len = 21;
        for (auto& w : word_dict)
            min_len = min(min_len, (int)w.size());
        if (min_len > n)
            return false;

        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; ++i)
            if (dp[i]) // can we continue from this index?
                for (auto& word : word_dict)
                    if (!dp[i + word.size()] && s.find(word, i) == i)
                        dp[i + word.size()] = true;
        return dp[n];
    }
};