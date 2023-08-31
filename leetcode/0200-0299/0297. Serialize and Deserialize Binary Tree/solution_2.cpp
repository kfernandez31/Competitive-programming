// Approach: Pre-order traversal.
// TC: serialize - O(n), deserialize - O(n)
// SC: serialize - O(n), deserialize - O(n)
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        function<void(TreeNode*)> aux = [&](TreeNode* v) {
            if (!v)
                out << "# ";
            else {
                out << v->val << ' ';
                aux(v->left);
                aux(v->right);
            }
        };
        aux(root);
        return out.str();
    }

    TreeNode* deserialize(string&& data) {
        istringstream in(move(data));
        function<TreeNode*()> aux = [&]() -> TreeNode* {
            string val; in >> val;
            return val == "#" ? nullptr : new TreeNode(stoi(val), aux(), aux());
        };
        return aux();
    }
};