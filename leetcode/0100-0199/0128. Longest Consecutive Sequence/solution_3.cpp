// Approach: Find largest component with a setsU.
// TC: O(n)
// SC: O(n)
class UnionFind {
    struct Set { int parent, size = 1; };
public:
    unordered_map<int, Set> sets;

    UnionFind(vector<int>& nums) {
        for (int num : nums)
            sets[num].parent = num;
    }
    
    int find(int a) {
        return (a == sets[a].parent) ? a : (sets[a].parent = find(sets[a].parent));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (sets[a].size < sets[b].size)
            swap(a, b);
        sets[a].size  += sets[b].size;
        sets[b].parent = a;
        return true;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf(nums);

        for (int num : nums) {
            if (uf.sets.count(num - 1))
                uf.join(num - 1, num);
            if (uf.sets.count(num + 1))
                uf.join(num + 1, num);
        }

        int ans = 0;
        for (int num : nums) 
            ans = max(ans, uf.sets[num].size);
        return ans;
    }
};