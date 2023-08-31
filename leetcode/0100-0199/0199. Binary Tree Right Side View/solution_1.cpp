// Approach: "Level-order" basically means BFS.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) 
            return {};
        vector<int> ans;
        queue<pair<int, TreeNode*>> q{{{0, root}}};
        while (!q.empty()) {             
            auto& [d, cur] = q.front(); q.pop();
            
            ans.resize(max((int)ans.size(), d + 1));
            ans[d] = cur->val;

            if (cur->left)
                q.push({d + 1, cur->left});
            if (cur->right)
                q.push({d + 1, cur->right});
        }
        return ans;
    }
};