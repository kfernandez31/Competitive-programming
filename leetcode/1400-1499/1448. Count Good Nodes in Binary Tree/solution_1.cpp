// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
    int good(TreeNode* root, int path_max) {
        if (!root)
            return 0;
        int ans = path_max <= root->val; 
        if (ans)
            path_max = root->val;
        return ans + good(root->left, path_max) + good(root->right, path_max);
    }
public:
    int goodNodes(TreeNode* root) {
        return good(root, INT_MIN);
    }
};