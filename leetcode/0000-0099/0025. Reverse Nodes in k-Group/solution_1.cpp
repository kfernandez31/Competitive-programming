// Approach: Find the k+1st node, reverse the k nodes before it, and then connect what was before them to the current node.
// TC: O(n)
// SC: O(1)
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next      = prev;
            prev           = cur;
            cur            = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return nullptr;
        if (k == 1)
            return head;
        ListNode *new_head = head;
        ListNode *prev = nullptr, *cur = head;
        ListNode *group_head = head, *prev_group_tail = nullptr;

        while (cur->next) 
            cur = cur->next;
        ListNode dummy(42);
        cur->next = &dummy;

        cur = head;
        for (int i = 0; cur; ++i) {
            if (i == k) {
                prev->next = nullptr;
                ListNode* rev = reverse(group_head);

                if (new_head == head)
                    new_head = rev;

                if (prev_group_tail)
                    prev_group_tail->next = rev;

                i = 0;
                group_head->next = cur;
                prev_group_tail = group_head;
                group_head = cur;
            }
            prev = cur;
            cur  = cur->next;
        }

        cur = new_head;
        while (cur->next != &dummy) 
            cur = cur->next;
        cur->next = nullptr;
        return new_head;
    }
};