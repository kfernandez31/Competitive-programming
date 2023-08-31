// Approach: Long addition.
// TC: O(m+n)
// SC: O(m+n)
class Solution {
public:
    ListNode* addWithCarry(int carry, ListNode* l1, ListNode* l2) {
        if (!carry && !l1 && !l2)
            return nullptr;
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode* tail = addWithCarry(sum / 10, l1 ? l1->next : nullptr, l2 ? l2->next : nullptr);
        return new ListNode(sum % 10, tail);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addWithCarry(0, l1, l2);
    }
};
