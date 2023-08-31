// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode* left  = invertTree(root->right);
            TreeNode* right = invertTree(root->left);
            root->left  = left;
            root->right = right;
        }
        return root;
    }
};