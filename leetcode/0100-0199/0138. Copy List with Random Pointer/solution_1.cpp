// Approach: Store the cloned nodes in a map.
// TC: O(n)
// SC: O(n)
class Solution {
    Node* clone(Node* cur, unordered_map<Node*, Node*>& clones) {
        if (!cur)
            return nullptr;
        if (!clones[cur]) {
            clones[cur] = new Node(cur->val);
            clones[cur]->next   = clone(cur->next, clones);
            clones[cur]->random = clone(cur->random, clones);
        }
        return clones[cur];
    }
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clones;
        return clone(head, clones);
    }
};