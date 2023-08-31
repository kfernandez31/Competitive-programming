// Approach: Simple backtracking.
// TC: O(n*4^n)
// SC: O(n)
class Solution {
    unordered_map<char, vector<char>> m = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
    };
public:
    vector<string> letterCombinations(string& digits) {
        int n = digits.size();
        if (n == 0) return {};
        
        vector<string> ans;
        string acc;

        function<void(int)> bt = [&](int i) {
            if (i == n) {
                ans.push_back(acc);
                return;
            }

            for (int letter : m[digits[i]]) {
                acc.push_back(letter);
                bt(i + 1);
                acc.pop_back();
            }
        };

        bt(0);
        return ans;
    }
};