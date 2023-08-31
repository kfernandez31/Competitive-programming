// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
    int find(TreeNode* root, int k) {
        if (!root)
            return 0;
        int l_sz = find(root->left, k);
        if (k == l_sz + 1)
            throw root->val;
        int r_sz = find(root->right, k - (l_sz + 1));
        return 1 + l_sz + r_sz;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        try {
            find(root, k);
            return -1;
        } catch (int val) {
            return val;
        }
    }
};