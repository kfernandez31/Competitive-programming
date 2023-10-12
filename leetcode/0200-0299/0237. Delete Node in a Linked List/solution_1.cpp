// Approach: Make the current node its successor, and delete the original successor.
// TC: O(1)
// SC: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        delete next;
     }
};