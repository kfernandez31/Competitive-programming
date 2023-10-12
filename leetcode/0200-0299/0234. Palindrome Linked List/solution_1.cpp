// Approach: Reverse a clone of the list, then traverse both and compare.
// TC: O(n)
// SC: O(n)
class Solution {
    ListNode* clone(ListNode* head) {
        ListNode *cur = head->next, *new_head = new ListNode(head->val), *cur_new = new_head;
        while (cur) {
            cur_new = cur_new->next = new ListNode(cur->val);
            cur     = cur->next;
        }
        return new_head;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next      = prev;
            prev           = cur;
            cur            = next;
        }
        return prev;
    } 

    bool equal(ListNode *a, ListNode *b) {
        while (a) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        return equal(head, reverse(clone(head)));
    }
};