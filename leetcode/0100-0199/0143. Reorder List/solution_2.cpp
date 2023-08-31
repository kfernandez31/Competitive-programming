// Approach: Find the middle of the list, reverse the second half and interleave with the first one.
// TC: O(n)
// SC: O(1)
class Solution {
    ListNode* reverseListIter(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next      = prev;
            prev           = cur;
            cur            = next;
        }
        return prev;
    }

    ListNode* splitAtMid(ListNode* head) {
        ListNode *slow = head, *fast = head, *prevslow;
        while (fast && fast->next) {
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevslow->next = nullptr;
        return slow;
    }

    void merge(ListNode* left, ListNode* right) {
        while (left) {
            ListNode *lnext = left->next, *rnext = right->next;
            left->next  = right;
            if (!lnext)
                break;
            right->next = lnext;
            left = lnext, right = rnext;
        }
    }
public:
    void reorderList(ListNode* head) {
        if (head->next)
            merge(head, reverseListIter(splitAtMid(head)));
    }
};