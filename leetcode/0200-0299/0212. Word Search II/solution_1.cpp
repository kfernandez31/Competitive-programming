// Approach: Construct a trie over the words, then perform an exhaustive search with backtracking. If a word has been found, unmark it in the trie.
// TC: O(klp + (mn)^2*p^(mn))
// SC: O(klp), k - |words|, l - avg. word length, p - alphabet size
struct Trie {
    struct Node {
        bool eow = false;
        unordered_map<char, Node*> children;
    };

    Node* root = new Node();

    Trie(vector<string>& words) {
        for (auto& w : words)
            insert(w);
    }

    void insert(string_view word) {
        Node* node = root;
        for (char c : word) {
            if (!node->children[c]) 
                node->children[c] = new Node();
            node = node->children[c];
        }
        node->eow = true;
    }
};

class Solution {
    static constexpr pair<int, int> dij[] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; 
public:
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        Trie trie(words);
        vector<string> ans;
        string acc(1);

        function<void(int, int, Trie::Node*)> bt = [&](int i, int j, Trie::Node* node) {
            if (node->eow) {
                ans.push_back(acc);
                node->eow = false;
            }

            char marker = '$';
            swap(grid[i][j], marker);

            for (auto& [di, dj] : dij) {
                int x = i + di;
                int y = j + dj;
                if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()) {
                    char c = grid[x][y];
                    if (c != '$') {
                        Trie::Node* next = node->children[c];
                        if (next) {
                            acc.push_back(c);
                            bt(x, y, next);
                            acc.pop_back();
                        }
                    }
                }
            }
            
            swap(grid[i][j], marker);
        };

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                char c = grid[i][j];
                Trie::Node* node = trie.root->children[c];
                if (node) {
                    acc[0] = c;
                    bt(i, j, node);
                }
            }
        }
        return ans;
    }
};