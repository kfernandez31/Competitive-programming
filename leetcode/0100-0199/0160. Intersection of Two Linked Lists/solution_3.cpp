// Approach: Mark nodes as visited in-place, then check for the flags. At the end, restore original values of the lists.
// TC: O(n+m)
// SC: O(1)
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
        ListNode* cur = a;
        while (cur) {
            cur->val *= -1;
            cur = cur->next;
        }

        ListNode* ans = nullptr;
        cur = b;
        while (cur) {
            if (!ans && cur->val < 0) 
                ans = cur;
            cur = cur->next;
        }

        cur = a;
        while (cur && cur->val < 0) {
            cur->val *= -1;
            cur = cur->next;
        }

        return ans;
    }
};