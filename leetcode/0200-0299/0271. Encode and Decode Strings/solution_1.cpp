// Approach: Prepend each word with its length.
// TC: encode - O(n), decode - O(n)
// SC: O(1)
class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (autog& s : strs)
            result += to_string(s.size()) + "#" + s;
        return result;
    }

    vector<string> decode(string& s) {
        vector<string> result;
        for (int i = 0; i < s.size();) {
            int hash_idx = s.find('#', i);
            int len = stoi(s.substr(i, hash_idx - i));
            string tok = s.substr(hash_idx + 1, len);
            result.push_back(move(tok));
            i = hash_idx + 1 + len;
        }
        return result;
    }
};