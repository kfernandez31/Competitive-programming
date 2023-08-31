// Approach: First verify the number of edges. Then, join nodes using a DSU and check whether there's only one component left.
// TC: O(n)
// SC: O(n)
class UnionFind {
    struct Set { int parent, size = 1; };
    vector<Set> sets;
public:
    int num_sets;
    
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
        --num_sets;
        return true;
    }

    (int n) : num_sets(n), sets(n + 1) {
        for (int i = 1; i <= n; ++i) 
            sets[i].parent = i; 
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        if (edges.size() != n - 1)
            return false;
        for (auto& e : edges) 
            uf.join(e[0], e[1]);
        return uf.num_sets == 1;
    }
};