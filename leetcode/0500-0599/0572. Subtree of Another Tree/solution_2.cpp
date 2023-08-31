// Approach: Like solution #1, but using string::find instead of KMP.
// TC: O(n+m)
// SC: O(n+m)
class Solution {
    string serialize(TreeNode* root) {
        if (!root)
            return "$";
        return '#' + to_string(root->val) + '#' + serialize(root->left) + '#' + serialize(root->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return serialize(root).find(serialize(subRoot)) != string::npos;
    }
};