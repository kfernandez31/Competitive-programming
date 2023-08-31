// Approach: Straightforward.
// TC: O(logn)
// SC: O(logn)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set seen;
        while (n != 1) {
            if (seen.count(n))
                return false;
            seen.insert(n);
            int digits_sq = 0;
            for (; n; n /= 10) {
                int digit  = n % 10;
                digits_sq += digit * digit;
            }
            n = digits_sq;
        }
        return true;
    }
};