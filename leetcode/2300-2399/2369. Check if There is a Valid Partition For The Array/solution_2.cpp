// Approach: Bottom-up DP.
// TC: O(n)
// SC: O(1)
class Solution {
    bool is_2n_plus_3m(int num) {
        for (int n = 0; 2 * n <= num; ++n) 
            if ((num - 2 * n) % 3 == 0)
                return true;
        return false;
    }
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        if (!is_2n_plus_3m(n))
            return false;

        bool dp[4] = {0, 0, 0, 1}; // the 1 is to make dp[-1] true
        for (int i = 0; i < n; ++i) 
            dp[i % 4]
                = (0 <= i - 1 && dp[(i + 2) % 4] && A[i - 1] == A[i])
                | (0 <= i - 2 && dp[(i + 1) % 4] && A[i - 2] == A[i - 1] && A[i - 1] == A[i])
                | (0 <= i - 2 && dp[(i + 1) % 4] && A[i - 2] + 1 == A[i - 1] && A[i - 1] + 1 == A[i]);
        return dp[(n - 1) % 4];
    }
};