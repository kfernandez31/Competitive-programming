// Approach: Straightforward - make the k-th node the new head.
// TC: O(n)
// SC: O(1)
class Solution {
    int len(ListNode* head) {
        int ans = 0;
        ListNode* cur = head;
        while (cur) {
            ++ans;
            cur = cur->next;
        }
        return ans;
    }

    ListNode* nth(ListNode* head, int n) {
        ListNode* cur = head;
        while (n--) 
            cur = cur->next;
        return cur;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        int n = len(head);
        k %= n;
        if (k == 0)
            return head;

        ListNode* par = nth(head, n - k - 1);
        ListNode* new_head = par->next;
        ListNode* last = nth(par, k);

        par->next  = nullptr;
        last->next = head; 
        
        return new_head;
    }
};