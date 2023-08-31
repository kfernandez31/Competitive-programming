// Approach: Similar to solution #1, but removes the next node instead of the current one.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int tailLen(ListNode* cur, int n) {
        if (!cur) 
            return 0;
        int tail_len = tailLen(cur->next, n);
        if (tail_len == n)
            cur->next = cur->next->next; // n is never 0 => cur->next->next is not NULL
        return 1 + tail_len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return tailLen(head, n) == n ? head->next : head;
    }
};