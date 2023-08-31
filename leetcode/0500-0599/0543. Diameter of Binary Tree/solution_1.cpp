// Approach: Sum the farthest distances left and right.
// TC: O(n)
// SC: O(n)
class Solution {
    int ans = 0;
    int aux(TreeNode* root) {
        if (!root)
            return 0;
        int left_dist  = aux(root->left);
        int right_dist = aux(root->right);
        ans = max(ans, left_dist + right_dist);
        return 1 + max(left_dist, right_dist);
    }
public:

    inline int diameterOfBinaryTree(TreeNode* root) {
        aux(root);
        return ans;
    }
};