// Approach: DFS.
// TC: O(n)
// SC: O(n)
class Solution {
    void traverse(TreeNode* root, int level, vector<int>& ans){
        if (!root) 
            return;
        if (level == ans.size()) 
            ans.push_back(root->val);
        traverse(root->right, level + 1, ans);
        traverse(root->left,  level + 1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, 0, ans);
        return ans;
    }
};