// Approach: Keep track of all traversed nodes.
// TC: O(m+n)
// SC: O(max(m,n))
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
        unordered_set<ListNode*> s;
        ListNode* cur = a;
        while (cur) {
            s.insert(cur);
            cur = cur->next;
        }
        cur = b;
        while (cur) {
            if (s.contains(cur))
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};