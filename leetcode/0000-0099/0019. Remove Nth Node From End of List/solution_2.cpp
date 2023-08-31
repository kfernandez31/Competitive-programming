// Approach: Abusing how you can modify C++ function signatures behind the scenes.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* node, int& n) {
        if (node) {
            node->next = removeNthFromEnd(node->next, n);
            if (1 == n--) // hacky bullshit
                return node->next;
        }
        return node;
    }
};