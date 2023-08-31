// Approach: DSU.
// TC: O(n)
// SC: O(n)
class UnionFind {
    struct Set { int parent, size = 1; };
    vector<Set> sets;
public:    
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

    UnionFind(int n) : sets(n + 1) {
        for (int i = 1; i <= n; ++i) 
            sets[i].parent = i; 
    }
};

class Solution {
public:    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (auto& edge : edges) 
            if (!uf.join(edge[0], edge[1]))
                return edge;
        return {};
    }
};