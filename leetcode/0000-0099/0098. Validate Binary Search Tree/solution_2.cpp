// Approach: Top-down. For the current node, check if it can be in its parent's substree.
// TC: O(n)
// SC: O(n)
class Solution {
    bool aux(TreeNode* root, long left, long right) {
        if (!root)
           return true;

        if (left < root->val && root->val < right)
            return aux(root->left, left, root->val) && aux(root->right, root->val, right);
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return aux(root, LLONG_MIN, LLONG_MAX);
    }
};