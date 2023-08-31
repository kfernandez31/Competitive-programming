// Approach: Straightforward.
// TC: insert - O(n), search - O(n), startsWith - O(n), n - |word|
// SC: O(#inserts * m * k), m - avg. word length, k - alphabet size
class Trie {
    struct Node {
        bool eow = false;
        unordered_map<char, Node*> children;
    };
    
    Node* root = new Node();

    Node* find(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->children[c])
                return nullptr;
            node = node->children[c];
        }
        return node;
    }
public:    
    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new Node();
                ++node->num_children;
            }
            node = node->children[c];
        }
        node->eow = true;
    }

    bool search(string& word) {
        Node* node = find(word);
        return node && node->eow;
    }
    
    bool startsWith(string& prefix) {
        return find(prefix);
    }
};