// Approach: Knuth-Morris-Pratt (KMP) over the serialized tree.
// TC: O(m+n)
// SC: O(m+n)
class Solution {
    void serialize(TreeNode* root, string& acc) {
        if (!root)
            acc += '$';
        else {
            acc += '#' + to_string(root->val) + '#';
            serialize(root->left, acc);
            acc += '#';
            serialize(root->right, acc);
        }
    }

    vector<int> make_lps(string& pat) {
        vector<int> lps(pat.size());
        int len = 0, i = 1;
        while (i < pat.size())
            if (pat[i] == pat[len])
                lps[i++] = ++len;
            else if (len == 0) 
                lps[i++] = 0;
            else
                len = lps[len - 1];
        return lps;
    }

    bool kmp(string& txt, string& pat, vector<int>& lps) {
        int i = 0, j = 0;
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                ++i, ++j;
                if (j == pat.size())
                    return true;
            } else if (j == 0)
                ++i;
            else
                j = lps[j - 1];
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string root_str, subroot_str;
        serialize(root, root_str);
        serialize(subRoot, subroot_str);
        auto lps = make_lps(subroot_str);
        return kmp(root_str, subroot_str, lps);
    }
};