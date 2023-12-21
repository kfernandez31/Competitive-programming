// Approach: Binary partition, then sort based on prefix.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto it = stable_partition(begin(logs), end(logs), [](string& s) {
            return isalpha(s.back());
        });

        sort(begin(logs), it, [](string& la, string& lb) {
            string_view va(la), vb(lb);
            auto ca = va.substr(va.find(' '));
            auto cb = vb.substr(vb.find(' '));
            return ca == cb ? la < lb : ca < cb;
        });

        return logs;   
    }
};