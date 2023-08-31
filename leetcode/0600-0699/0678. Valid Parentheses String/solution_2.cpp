// Approach: Maintain a range of possible values of currently open parentheses.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool checkValidString(string& s) {
        int min_open = 0, max_open = 0;
        for (char c : s) {
            if (c == '(') 
                ++min_open, ++max_open;
            else {
                if (c == ')') {
                    --min_open, --max_open;
                    if (max_open < 0)
                        return false;
                } else if (c == '*')
                    --min_open, ++max_open;
                
                min_open = max(min_open, 0);
            }
        }

        return min_open == 0; // is 0 in the range [min, max]
    }
};