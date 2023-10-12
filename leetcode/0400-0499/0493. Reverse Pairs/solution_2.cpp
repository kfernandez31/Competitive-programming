// Approach: Fenwick tree, suffix-sum variant.
// TC: O(nlogn)
// SC: O(n)
class FenwickTree {
    static inline int lsb(int i) { return i & -i; }
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1) {}

    int query(int l) {
        int sum = 0;
        for (; l < tree.size(); l += lsb(l)) 
            sum += tree[l];
        return sum;
    }

    void update(int i) {
        for (; i > 0; i -= lsb(i)) 
            ++tree[i];
    }
};

class Solution {
    #define idx(s, x) (lower_bound(s.begin(), s.end(), x) - s.begin())
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        vector<long> s(n);
        for (int i = 0; i < n; ++i)
            s[i] = nums[i];
        sort(s.begin(), s.end());

        FenwickTree ft(n);
        int ans = 0;
        for (int num : nums) {
            ans += ft.query(1 + idx(s, 2ll * num + 1)); // the 1 is required so as to not occupy the tree's 0 cell
            ft.update(1 + idx(s, num));
        }
        return ans;
    }
};