// Approach: Use a dummy node.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int aux(ListNode* prev, ListNode* cur, int n) {
        if (!cur) 
            return 0;
        int len = 1 + aux(cur, cur->next, n);
        if (len == n)                
            prev->next = cur->next;
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(42, head);
        int len = aux(nullptr, &dummy, n);
        if (len == n)
            return nullptr;
        return dummy.next;
    }
};