// Approach: Align two pointers in the same position in within the lists, then advance simultaneously.
// TC: O(n+m)
// SC: O(1)
class Solution {
    int length(ListNode* head) {
        int ans = 0;
        ListNode* cur = head;
        while (cur) {
            ++ans;
            cur = cur->next;
        }
        return ans;
    }
public:
    ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
        int m = length(a), n = length(b), d = abs(m - n);
        if (m > n) 
            while (d--)
                a = a->next;
        else
            while (d--)
                b = b->next;
        while (a && b) {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};