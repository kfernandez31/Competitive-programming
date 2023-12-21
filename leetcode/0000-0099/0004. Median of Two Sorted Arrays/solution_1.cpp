// Approach: K-th element. TODO:
// TC: O(?)
// SC: O(?)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& xs, vector<int>& ys) {
        int m = xs.size(), n = ys.size();

        function<int(int, int, int)> aux = [&](int i, int j, int k) {
            if (i >= m) 
                return ys[j + k - 1];
            if (j >= n) 
                return xs[i + k - 1];
            if (k == 1) 
                return min(xs[i], ys[j]);

            int p = k / 2;
            int x = i + p - 1 < m ? xs[i + p - 1] : INT_MAX;
            int y = j + p - 1 < n ? ys[j + p - 1] : INT_MAX;

            return x < y ? aux(i + p, j, k - p) : aux(i, j + p, k - p);
         };

        int a = aux(0, 0, (m + n + 1) / 2);
        int b = aux(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }
};