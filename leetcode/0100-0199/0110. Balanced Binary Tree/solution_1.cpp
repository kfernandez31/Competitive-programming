// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
    int bal(TreeNode* root) {
        if (!root)
            return 0;
        int left_h  = bal(root->left);
        int right_h = bal(root->right);
        if (abs(left_h - right_h) > 1)
            throw 42;
        return 1 + max(left_h, right_h);
    }
public:
    bool isBalanced(TreeNode* root) {
        try {
            bal(root);
            return true;
        } catch (...) {
            return false;
        }
    }
};