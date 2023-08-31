// Approach: Keep track of all traversed nodes.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> m;
        ListNode* cur = head;
        for (; cur; cur = cur->next) {
            if (m.count(cur))
                return true;
            m.insert(cur);
        }
        return false;
    }
};