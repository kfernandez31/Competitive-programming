// Approach: For the given root, find its position in the inorder array, recurse for both halves and then join them.
// TC: O(n^2)
// SC: O(n)
class Solution {
    TreeNode* build(int* pre, int* in, int n) {
        if (n == 0)
            return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        int mid = 0;
        while (in[mid] != pre[0])
            ++mid;
        return new TreeNode(
            pre[0],
            build(pre + 1, in, mid),
            build(pre + mid + 1, in + mid + 1, n - mid - 1)
        );
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(pre.data(), in.data(), pre.size());
    }
};