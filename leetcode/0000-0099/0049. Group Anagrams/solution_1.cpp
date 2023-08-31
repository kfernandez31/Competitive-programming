// Approach: Bucket sort with the key being the sorted string.
// TC: O(nklogk), k - avg. string length
// SC: O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[move(key)].push_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto& [_, v] : groups) 
            ans.push_back(move(v));
        return ans;
    }
};