class SegmentTree {
    inline int len(int a, int b) { return b - a + 1; }

    void push(int v, int l, int r, int len) {
        if (lazy[v] != 0) {
            tree[l] += lazy[v] * len;
            tree[r] += lazy[v] * len;

            lazy[l] += lazy[v];
            lazy[r] += lazy[v];

            lazy[v] = 0;
        }
    }

    void update(int v, int lo, int hi, int qa, int qb, int val) {
        if (qb < lo || hi < qa) 
            return;
        if (qa <= lo && hi <= qb) {
            tree[v]  = val * len(qa, qb);
            lazy[v] += val;
            return;
        } 
        int l = 2 * v, r = l + 1;
        push(v, l, r, len(lo, hi) / 2);

        int mid = (lo + hi) / 2;
        update(l, lo     , mid, qa, qb, val);
        update(r, mid + 1, hi,  qa, qb, val);

        tree[v] = tree[l] + tree[r];
    }

    int query(int v, int lo, int hi, int qa, int qb) {
        if (qb < lo || hi < qa) 
            return 0;
        if (qa <= lo && hi <= qb) 
            return tree[v];
        
        int l = 2 * v, r = l + 1;
        push(v, l, r, len(lo, hi) / 2);

        int mid = (lo + hi) / 2;
        int l_res = query(l, lo     , mid, qa, qb);
        int r_res = query(r, mid + 1, hi,  qa, qb);

        return l_res + r_res;
    }

    vector<int> tree, lazy;
    int base;
public:
    SegmentTree(int base) { //TODO: ctor z wartości w O(n)
        this->base = 1 << (int)ceil(log2(base));
        tree.resize(2 * this->base);
        lazy.resize(2 * this->base);
    }

    void update(int qa, int qb, int val) {
        update(1, 1, base, qa + 1, qb + 1, val);
    }

    int query(int qa, int qb) {
        return query(1, 1, base, qa + 1, qb + 1);
    }
};