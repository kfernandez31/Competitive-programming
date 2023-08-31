// Approach: Bottom=up.
// TC: O(n)
// SC: O(n)
class Solution {
    pair<long, long> aux(TreeNode* root) {
        if (!root)
            return {LLONG_MAX, LLONG_MIN};

        auto [l_min, l_max] = aux(root->left);
        if (l_max >= root->val)
            throw 42;

        auto [r_min, r_max] = aux(root->right);
        if (root->val >= r_min)
            throw 42;

        return {
            min((long)root->val, min(l_min, r_min)),
            max((long)root->val, max(l_max, r_max))
        };
    }
public:
    bool isValidBST(TreeNode* root) {
        try {
            aux(root);
            return true;
        } catch (...) {
            return false;
        }
    }
};