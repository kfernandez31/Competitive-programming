// Approach: Like solution #1, but iterative.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* reverseListIter(ListNode* head) {
        ListNode* prev = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next      = prev;
            prev           = cur;
            cur            = next;
        }
        return prev;
    }
};