// Approach: Reverse the 2nd half of the list, then traverse both halves and compare.
// TC: O(n)
// SC: O(1)
class Solution {
    int length(ListNode* head) {
        int ans = 0;
        ListNode *cur = head;
        while (cur) {
            ++ans;
            cur  = cur->next;
        }
        return ans;
    }

    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode *prev = nullptr, *cur = begin;
        while (cur != end) {
            ListNode *next = cur->next;
            cur->next      = prev;
            prev           = cur;
            cur            = next;
        }
        return prev;
    } 

    bool equal(ListNode *a, ListNode *b) {
        while (a && b) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }

    ListNode* middle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        int n = length(head);        
        ListNode* mid = middle(head), *rev = reverse(head, mid);
        return equal(rev, n % 2 == 0 ? mid : mid->next);
    }
};