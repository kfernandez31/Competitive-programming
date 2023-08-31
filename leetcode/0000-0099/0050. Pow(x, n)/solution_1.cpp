// Approach: Recursive.
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    double myPow(double x, long n) {
        if (x == 0.0 || x == 1.0)
            return x;
        if (x == -1.0)
            return n % 2 == 0 ? +1.0 : -1.0; 
        if (n < 0) 
            x = 1 / x, n *= -1.0;

        double ans = 1.0;
        while (n) {
            ans  *= (n % 2 == 0 ? 1.0 : x);  
            x    *= x;
            n    /= 2;
        }
        return ans;
    }
};
