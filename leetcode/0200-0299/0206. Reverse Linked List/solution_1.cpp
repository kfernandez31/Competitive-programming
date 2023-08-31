// Approach: Reverse each arrow, but keep the other end in a temporary variable.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    ListNode* reverseListRec(ListNode* cur, ListNode* prev) {
        if (!cur)
            return prev;
        ListNode* next = cur->next;
        cur->next = prev;
        return reverseListRec(next, cur);
    }

    ListNode* reverseList(ListNode* head) {
        return reverseListRec(head, nullptr);
    }
};