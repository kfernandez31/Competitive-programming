// Approach: Straightforward - lexicographical comparison, normalize each revision id.
// TC: O(max(m,n))
// SC: O(max(m,n)) (due to substr, TODO: improve)
class Solution {
    pair<int, int> next(string& s, int l) {
        int r = s.find('.', l);
        if (r == string::npos)
            return {0, s.size()};
        return {stoi(s.substr(l, r - l)), r + 1};
    }
public:
    int compareVersion(string& vid1, string& vid2) {
        vid1 += '.', vid2 += '.';
        int m = vid1.size(), n = vid2.size();
        int i = 0, j = 0;
        while (i < m || j < n) {
            auto [tok_a, next_i] = next(vid1, i);
            auto [tok_b, next_j] = next(vid2, j);
            if (tok_a < tok_b)
                return -1;
            if (tok_a > tok_b)
                return +1;
            i = next_i, j = next_j;
        }
        return 0;
    }
};