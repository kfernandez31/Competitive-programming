// Approach: DSU with component counter.
// TC: connect - O(1), query - O(1)
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

    UnionFind(int n) : num_sets(n), sets(n + 1) {
        for (int i = 1; i <= n; ++i) 
            sets[i].parent = i; 
    }
};

class ConnectingGraph3 {
    UnionFind uf;
public:
    ConnectingGraph3(int n) : uf(n) {}

    void connect(int a, int b) { uf.join(a, b); }
    int query() { return uf.num_sets; }
};