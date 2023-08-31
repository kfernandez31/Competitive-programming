// Approach: Store the cloned graph in a hashmap for quick access to neighbors.
// TC: O(n+m)
// SC: O(n)
class Solution {
    Node* aux(Node* cur, unordered_map<Node*, Node*>& clones) {
        clones[cur] = new Node(cur->val);
        for (Node* next : cur->neighbors)
            if (clones[next])
                clones[cur]->neighbors.push_back(clones[next]);
            else
                clones[cur]->neighbors.push_back(aux(next, clones));
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