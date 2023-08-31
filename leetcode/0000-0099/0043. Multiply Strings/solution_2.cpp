// Approach: Like solution #1, but may be more readable to some.
// TC: O(mn)
// SC: O(m+n)
class Solution {
    void to_numeric(string& num)   { for (char& c : num) c -= '0'; }
    void from_numeric(string& num) { for (char& c : num) c += '0'; }
public:
    string multiply(string& a, string& b) {
        if (a == "0" || b == "0") return "0";
        if (a == "1") return b;
        if (b == "1") return a;
        
        to_numeric(a), reverse(a.begin(), a.end());
        to_numeric(b), reverse(b.begin(), b.end());
        int m = a.size(), n = b.size();

        string c(m + n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i + j]     += a[i] * b[j];
                c[i + j + 1] += c[i + j] / 10;
                c[i + j]     %= 10;
            }
        }

        if (c.back() == 0) // drop a leading zero
            c.pop_back();
        from_numeric(c), reverse(c.begin(), c.end());
        return c;
    }
};