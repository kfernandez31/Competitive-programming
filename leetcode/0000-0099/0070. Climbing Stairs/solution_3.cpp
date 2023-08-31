// Approach: Matrix multiplication.
// TC: O(logn)
// SC: O(logn)
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) 
            return n;
        // [F(n+1)][ F(n) ]
        // [ F(n) ][F(n-1)]
        vector<int> fibs = {1, 1, 1, 0};
        return mat_pow(fibs, n)[0];
    }
private:
    vector<int> mat_mul(vector<int>& A, vector<int>& B) {
        return {
            A[0] * B[0] + A[1] * B[2],
            A[0] * B[1] + A[1] * B[3],
            A[2] * B[0] + A[3] * B[2],
            A[2] * B[1] + A[3] * B[3]
        };
    }
    vector<int> mat_pow(vector<int>& A, int n){
        if (n == 1) 
            return A;
        vector<int> B = mat_pow(A, n / 2);
        B = mat_mul(B, B);
        if (n % 2 == 1)
            B = mat_mul(B, A);
        return B;
    }
};