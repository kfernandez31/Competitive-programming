// Approach: First duplicate the original nodes. Then, assign the duplicates' random pointers. Finally, assign the duplicates' next pointers.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node* cur = head;
        // duplicate original nodes
        while (cur) {
            Node* next = cur->next;
            cur->next  = new Node(cur->val);
            cur        = cur->next->next = next;
        }
        // assign the `random` ptrs 
        cur = head;
        while (cur) {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        // fix the original list, assign the `next` ptrs
        Node* ans = head->next;
        cur = head;
        while (cur) {
            Node* next_old = cur->next->next;
            if (next_old)
                cur->next->next = next_old->next;
            cur = cur->next = next_old;
        }
        return ans;
    }
};