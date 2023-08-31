// Approach: Like solution #1, but also works for unicode (follow up).
// TC: O(m+n), k - alphabet size
// SC: O(k)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for (char c : s)
            ++cnt[c];
        for (char c : t) 
            if (--cnt[c] == 0)
                cnt.erase(c);
        return cnt.empty();
    }
};