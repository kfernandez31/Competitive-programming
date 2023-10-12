// Approach: Enumerate each node, then at each level take the difference between the outmost elements.
// TC: O(n)
// SC: O(n)
class Solution {
    using ull = unsigned long long;
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        queue<pair<TreeNode*, ull>> q{{{root, 1}}};
        while (!q.empty()) {
            ans = max(ans, q.back().second - q.front().second);
            int sz = q.size();
            while (sz--) {
                auto [v, i] = q.front(); q.pop();
                if (v->left)  q.push({v->left,  2 * i});
                if (v->right) q.push({v->right, 2 * i + 1});
            }
        }
        return ans + 1;
    }
};