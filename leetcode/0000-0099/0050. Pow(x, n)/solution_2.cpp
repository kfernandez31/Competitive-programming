// Approach: Recursive.
// TC: O(logn)
// SC: O(logn)
class Solution {
    double aux(double x, long n) {
        if (n == 0)
            return 1.0;
        double y = aux(x, n / 2);
        return y * y * (n % 2 == 0 ? 1.0 : x);  
    }
public:
    double myPow(double x, int n) {
        if (x == 0.0 || x == 1.0)
            return x;
        if (x == -1.0)
            return n % 2 == 0 ? +1.0 : -1.0; 
        if (n < 0) 
            x = 1 / x, n *= -1.0;
        return aux(x, n);
    }
};