// Approach: Straightforward but doesn't use the BST property.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    tuple<bool, bool, TreeNode*> find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return {false, false, nullptr};

        auto [left_p_fnd, left_q_fnd, left_lca] = find(root->left, p, q);
        if (left_lca)
            return {true, true, left_lca};

        auto [right_p_fnd, right_q_fnd, right_lca] = find(root->right, p, q);
        if (right_lca)
            return {true, true, right_lca};

        tuple<bool, bool, TreeNode*> ans;
        if (left_p_fnd || right_p_fnd || root->val == p->val)
            get<0>(ans) = true;
        if (left_q_fnd || right_q_fnd || root->val == q->val)
            get<1>(ans) = true;
        get<2>(ans) = (get<0>(ans) && get<1>(ans)) ? root : nullptr;
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return get<2>(find(root, p, q));
    }
};