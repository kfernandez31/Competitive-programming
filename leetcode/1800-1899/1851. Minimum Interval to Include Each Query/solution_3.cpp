// Approach: Use a range-update, point-query segment tree.
// TC: O(nlogr+qlogr), r - range of nums
// SC: O(r)
class SparseSegTree {
    class Node {
        int start, end, min = INT_MAX;
        Node *left = nullptr, *right = nullptr;
    public:
        Node(int start, int end) : start(start), end(end) {}

        void update(int lo, int hi, int val) {
            if (hi < start || end < lo) 
                return;
            if (lo <= start && end <= hi) {
                min = std::min(min, val);
                return;
            }
            
            int mid = start + (end - start) / 2;

            if (!left)
                left = new Node(start, mid);
            left->update(lo, hi, val);

            if (!right)
                right = new Node(mid + 1, end);
            right->update(lo, hi, val);
        }

        int query(int q) {
            if (q < start || end < q) 
                return INT_MAX;
            if (start == end)
                return min;

            int mid = start + (end - start) / 2;

            if (q <= mid) 
                return std::min(min, left  ? left->query(q)  : INT_MAX);
            else
                return std::min(min, right ? right->query(q) : INT_MAX);
        }
    };

    Node* root;
public:
    SparseSegTree(int start, int end) : root(new Node(start, end)) {}

    void update(int lo, int hi, int val) { root->update(lo, hi, val); }

    int query(int q) { return root->query(q); }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivs, vector<int>& qs) {
        SparseSegTree sst(1, 1e7 + 1);

        for (auto& iv : ivs)
           sst.update(iv[0], iv[1], iv[1] - iv[0] + 1);

        vector<int> ans;
        for (int q : qs) {
            int v = sst.query(q);
            ans.push_back(v == INT_MAX ? -1 : v);
        }

        return ans;
    }
};