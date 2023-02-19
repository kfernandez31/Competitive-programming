#include <bits/stdc++.h>
using namespace std;

const int maxN = 1 << 18;
int entryTime[maxN];
int exitTime[maxN];
long long color[maxN];
int n, q, t;
vector<int> graph[maxN];

struct node {
    int fst_color;
    int fst_count;
    int snd_color;
    bool is_good;

    node(bool is_good = true):
        fst_color(-1 * !is_good), 
        fst_count(0),
        snd_color(0),  
        is_good(is_good) {}

    node(int fst_color, int fst_count, int snd_color): 
        fst_color(fst_color), 
        fst_count(fst_count), 
        snd_color(snd_color), 
        is_good(true) {}

    node(const node& other):
        fst_color(other.fst_color), 
        fst_count(other.fst_count), 
        snd_color(other.snd_color), 
        is_good(other.is_good) {}
};

node tree[maxN << 1];

node add(const node* lhs, const node* rhs) {
    if (!lhs->is_good || !rhs->is_good) 
        return node(false);

    if (!lhs->fst_color) 
        return node(*rhs);
    if (!rhs->fst_color) 
        return node(*lhs);

    if (lhs->fst_color == rhs->fst_color) {
        if (!lhs->snd_color && !rhs->snd_color) 
            return node(lhs->fst_color, lhs->fst_count + rhs->fst_count, 0);
        else if (lhs->snd_color && !rhs->snd_color) 
            return node(lhs->fst_color, lhs->fst_count + rhs->fst_count, lhs->snd_color);
        else if (!lhs->snd_color && rhs->snd_color) 
            return node(lhs->fst_color, lhs->fst_count + rhs->fst_count, rhs->snd_color);   
    } else {
        if (!lhs->snd_color && !rhs->snd_color) {
            if (lhs->fst_count == 1)
                return node(rhs->fst_color, rhs->fst_count, lhs->fst_color);
            else if (rhs->fst_count == 1) 
                return node(lhs->fst_color, lhs->fst_count, rhs->fst_color);
        } 
        else if ((lhs->snd_color && !rhs->snd_color) && (lhs->snd_color == rhs->fst_color && lhs->fst_count == 1))
            return node(rhs->fst_color, 1 + rhs->fst_count, lhs->fst_color);
        else if ((!lhs->snd_color && rhs->snd_color) && (rhs->snd_color == lhs->fst_color && rhs->fst_count == 1))
            return node(lhs->fst_color, 1 + lhs->fst_count, rhs->fst_color);
    }

    return node(false);
}

void update(int v, int x) {
    v += maxN;
    tree[v] = node(x, 1, 0);
    for (v /= 2; v > 0; v /= 2) {
        tree[v] = add(&tree[2 * v], &tree[2 * v + 1]);
    }
}

bool query(int l, int r) {
    node acc = node();
    for (
        l += maxN - 1, r += maxN + 1;
        r - l > 1;
        l /= 2, r /= 2
    ) {
        if (l % 2 == 0) {
            acc = add(&acc, &tree[l + 1]);
        }
        if (r % 2 == 1) {
            acc = add(&acc, &tree[r - 1]);
        }
    }
    return acc.is_good;
}

void dfs(int cur) {
    entryTime[cur] = ++t;
    for (int next : graph[cur]) {
        if (!entryTime[next]) {
            dfs(next);
        }
    }
    exitTime[cur] = t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        graph[parent].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        int c = color[i];
        update(entryTime[i], c);
    }

    while (q) {
        int v, x;
        char cmd;
        cin >> cmd >> v;
        if (cmd == '?') {
            cout << (query(entryTime[v], exitTime[v])? "TAK\n" : "NIE\n");
            q--;
        } else if (cmd == 'z') {
            cin >> x;
            update(entryTime[v], x);
            q--;
        }
    }

    return 0;
}
