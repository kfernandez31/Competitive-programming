// Approach: Combinatorics. Pick which of the (m-1)+(n-1) moves are horizontal, the rest is vertical.
// TC: O(min(n, m))
// SC: O(min(n, m))
class Solution {
    static long choose(int n, int k) {
        if (k == 0 || n == k)
            return 1;
        return n * choose(n - 1, k - 1) / k;
    }
public:
    int uniquePaths(int m, int n) {
        return choose((n - 1) + (m - 1), min(m, n) - 1);
    }
};