// Approach: Maintain two heads and append the current node to either of them. Finally, join the two.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = nullptr, *r = nullptr;
        ListNode *l_head = nullptr, *r_head = nullptr;
        ListNode *cur = head;
        for (;cur; cur = cur->next) {
            if (cur->val < x) {
                if (!l)
                    l_head = l = cur;
                else 
                    l = l->next = cur;
            } else {
                if (!r)
                    r_head = r = cur;
                else 
                    r = r->next = cur;
            }
        }

        if (l)
            l->next = r_head;
        if (r)
            r->next = nullptr;

        if (l_head) 
            return l_head;
        return r_head;
    }
};
