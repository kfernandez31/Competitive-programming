// Approach: At each step, shift the result and append to it one digit.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        if (x < 0)        return -reverse(-x);

        int ans = 0;
        for (; x; x /= 10) {
            if (ans > INT_MAX / 10)
                return 0;
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
};