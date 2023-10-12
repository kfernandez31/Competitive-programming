// Approach: "Patience (solitaire) sort"
// TC: O(r+nlogn), r - range of nums
// SC: O(r)
class FenwickTree {
    inline int lsb(int i) { return i & -i; }
    vector<int> data;
public:
    FenwickTree(int n) : data(n + 1) {}

    int query(int r) {
        int ans = 0;
        for (; r > 0; r -= lsb(r)) 
            ans = max(ans, data[r]);
        return ans;
    }
    
    void update(int i, int val) {
        for (; i < data.size(); i += lsb(i))
            data[i] = max(data[i], val);
    }
};

class Solution {
    static const int OFFSET = 1e4;
public:
    int lengthOfLIS(vector<int>& nums) {
        FenwickTree ft(2 * OFFSET);

        int ans = 0;
        for (int num : nums) {
            num += OFFSET;
            int len = 1 + ft.query(num - 1); 
            ans = max(ans, len);
            ft.update(num, len);
        }

        return ans;
    }
};