// Approach: DFS.
// TC: O(n)
// SC: O(logn)
class Solution {
    int ans = -1001;

    int aux(TreeNode* root) {
        if (!root)
            return -1;
        int left  = max(0, aux(root->left));
        int right = max(0, aux(root->right));

        ans = max(ans, root->val + left + right); // take both paths if they're non-negative
        return root->val + max(left, right);      // take only one path for propagating upwards
    }
public:
    int maxPathSum(TreeNode* root) {
        aux(root);
        return ans;
    }
};