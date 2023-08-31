// Approach: A slight rewrite of solution #1. Here we enter a node regardless of whether it was cloned.
// TC: O(n+m)
// SC: O(n)
class Solution {
    Node* aux(Node* cur, unordered_map<Node*, Node*>& clones) {
        if (!clones[cur]) {
            clones[cur] = new Node(cur->val);
            for (Node* next : cur->neighbors)
                clones[cur]->neighbors.push_back(aux(next, clones));
        }
                
        return clones[cur];
    }
    
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> clones;
        return aux(node, clones);
    }
};