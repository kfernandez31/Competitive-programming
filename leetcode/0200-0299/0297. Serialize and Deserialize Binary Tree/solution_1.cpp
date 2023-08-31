// Approach: BFS (level-order traversal).
// TC: serialize - O(n), deserialize - O(n)
// SC: serialize - O(n), deserialize - O(n)
class Codec {
public:
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            TreeNode* v = q.front(); q.pop();
            if (!v)
                ans += "# ";
            else {
                ans += to_string(v->val) + " ";
                q.push(v->left);
                q.push(v->right);
            }
        }
        return ans;
    }

    TreeNode* deserialize(string&& data) {
        istringstream is(move(data));
        queue<TreeNode*> q;

        auto next_node = [&]() -> TreeNode* {
            string val; is >> val;
            if (val == "#")
                return nullptr;
            TreeNode* node = new TreeNode(stoi(val));
            q.push(node);
            return node;
        };

        TreeNode* root = next_node();
        while (!q.empty()) {
            TreeNode* v = q.front(); q.pop();
            v->left  = next_node();
            v->right = next_node();
        }
        return root;
    }
};