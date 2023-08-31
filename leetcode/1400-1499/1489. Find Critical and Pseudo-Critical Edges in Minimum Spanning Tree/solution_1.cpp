// Approach: Calculate the MST's cost and then check if excluding the current edge increases it (then it's critical) and if including it does result in an MST (then it's pseudo-critical).
// TC: O(mlogm + m*kruskal) = O(mlogm + m(m+n)) = O(m(n+logm))
// SC: O(m+n)
class UnionFind {
    struct Set { int parent, size = 1; };
    vector<Set> ds;
public:
    int num_sets;
    
    int find(int a) {
        return (a == ds[a].parent) ? a : (ds[a].parent = find(ds[a].parent));
    }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return false;
        if (ds[a].size < ds[b].size)
            swap(a, b);
        ds[a].size  += ds[b].size;
        ds[b].parent = a;
        --num_sets;
        return true;
    }

    UnionFind(int n) : num_sets(n), ds(n) {
        for (int i = 0; i < n; ++i) 
            ds[i].parent = i; 
    }
};

class Solution {
    int kruskal(int n, vector<vector<int>>& edges, int drop, int take) {
        UnionFind uf(n);
        int cost = 0;
        if (take != -1) {
            uf.join(edges[take][0], edges[take][1]);
            cost += edges[take][2];
        }

        for (int i = 0; i < edges.size() && uf.num_sets > 1; ++i) 
            if (i != drop && uf.join(edges[i][0], edges[i][1])) 
                cost += edges[i][2];
            
        return uf.num_sets == 1 ? cost : INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) 
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });

        int mst_cost = kruskal(n, edges, -1, -1);
        vector<vector<int>> ans(2);
        for (int i = 0; i < edges.size(); ++i) {  
            int idx = edges[i][3];
            if (kruskal(n, edges, i, -1) > mst_cost) 
                ans[0].push_back(idx);
            else if (kruskal(n, edges, i, i) == mst_cost) 
                ans[1].push_back(idx);
        }
        return ans;
    }
};