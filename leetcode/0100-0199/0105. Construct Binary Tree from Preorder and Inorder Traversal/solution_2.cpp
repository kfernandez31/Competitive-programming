// Approach: Like solution #1, but precompute the positions of nodes in the inorder array.
// TC: O(n)
// SC: O(n)
class Solution {
    unordered_map<int, int*> in_ptr;
    TreeNode* build(int* pre, int* in, int n) {
        if (n == 0)
            return nullptr;
        ptrdiff_t mid = in_ptr[pre[0]] - in; 
        return new TreeNode(
            pre[0],
            build(pre + 1, in, mid),
            build(pre + mid + 1, in + mid + 1, n - mid - 1)
        );
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for (int i = 0; i < in.size(); ++i)
            in_ptr[in[i]] = in.data() + i;
        return build(pre.data(), in.data(), pre.size());
    }
};