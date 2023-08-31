// Approach: Long addition.
// TC: O(n),
// SC: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size(), carry = 1, i = 0;
        reverse(v.begin(), v.end());
        
        for (; i < n && carry; ++i) {
            int sum = v[i] + carry;
            v[i]   = sum % 10;
            carry  = sum / 10;
        }

        if (i == n && carry)
            v.push_back(1);
        reverse(v.begin(), v.end());
        return v;
    }
};