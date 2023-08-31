// Approach: Return the first which contains p and q. We can check inclusion using the BST property.
// TC: O(n)
// SC: O(n)
class Solution {
    TreeNode* find(TreeNode* root, int lo, int hi) {
        if (!root)
            return nullptr;        
        if (hi < root->val)
            return find(root->left, lo, hi);
        if (root->val < lo)
            return find(root->right, lo, hi);
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lo = min(p->val, q->val);
        int hi = max(p->val, q->val);
        return find(root, lo, hi);
    }
};