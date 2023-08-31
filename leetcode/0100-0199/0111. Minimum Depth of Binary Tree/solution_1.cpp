// Approach: Straightforward. If one child is null, pick the result for the second one.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lres = minDepth(root->lres);
        int rres = minDepth(root->rres);
        return 1 + (lres && rres) ? min(lres, rres) : max(lres, rres);
    }
};