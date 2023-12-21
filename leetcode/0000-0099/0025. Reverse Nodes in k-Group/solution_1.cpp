// Approach: Find the first and the last nodes of the current group, reverse the group, pin the previous group's end to its new start and pin its end to the start of the next group.
// TC: O(n)
// SC: O(1)
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        ListNode dummy(42, head);
        ListNode* cur = &dummy;
        while (cur) {
            ListNode* first = cur->next;
            ListNode* last  = first;
            for (int i = 0; last && i < k - 1; ++i) 
                last = last->next;
            if (!last)
                break;

            ListNode* next = last->next;
            last->next = nullptr;

            ListNode* rev = reverse(first);
            cur->next = rev;

            first->next = next;

            cur = first;
        }

        return dummy.next;
    }
};