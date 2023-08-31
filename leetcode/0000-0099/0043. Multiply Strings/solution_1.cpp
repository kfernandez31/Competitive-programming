// Approach: Long multiplication.
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

        to_numeric(a), to_numeric(b);
        int m = a.size(), n = b.size();

        string c(m + n, 0);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                c[i + j + 1] += a[i] * b[j];
                c[i + j]     += c[i + j + 1] / 10;
                c[i + j + 1] %= 10;
            }
        }

        // drop leading zeros
        c.erase(c.begin(), find_if(c.begin(), c.end(), [](int v) { return v != 0; }));
        from_numeric(c);
        return c;
    }
};