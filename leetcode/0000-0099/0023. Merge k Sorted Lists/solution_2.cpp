// Approach: Like solution 1, but with a dummy node.
// TC: O(k*l*logk), l - avg. list length
// SC: O(k)
class Solution {
public:  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for (auto& l : lists)
            if (l) pq.push({-l->val, l});

        ListNode dummy(42), *temp = &dummy;
        while (!pq.empty()) {
            auto [val, l] = pq.top(); pq.pop();

            temp = temp->next = l;

            if (l->next)
                pq.push({-l->next->val, l->next});
        }        
        return dummy.next;
    }
};