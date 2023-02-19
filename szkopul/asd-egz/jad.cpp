#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int maxN = 1 << 19;

vector<int> tree[2 * maxN];
int color[maxN + 1];
int n, m;

void update(int l, int r, int x) {
    l += maxN - 1;
    r += maxN + 1;
    while (r - l > 1) {
        if (l % 2 == 0) {
            tree[l + 1].push_back(x);
        }
        if (r % 2 == 1) {
            tree[r - 1].push_back(x);
        }
        l /= 2;
        r /= 2;
    }
}

bool dfs(int cur) {
    color[cur] = GRAY;

    int v = cur + maxN;
    while (v) {
        for (int next : tree[v]) {
            if (color[next] == WHITE && dfs(next) == true) {
                return true;
            } else if (color[next] == GRAY) {
                return true;
            }
        }
        v /= 2;
    }

    color[cur] = BLACK;
    return false;
}

// void merge_all(vector<pair<int, int>>& ivals) {
//     sort(ivals.begin(), ivals.end());
//     int prev = 0;
//     for (const auto& cur : ivals) {
//         // cur starts before prev ends -> overlap
//         if (cur.first <= ivals[prev].second) { 
//             ivals[prev].second = max(ivals[prev].second, cur.second);
//         } else {
//             prev++;
//             ivals[prev] = cur;
//         }
//     }

//     ivals.resize(prev + 1);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, l, r;
        cin >> v >> l >> r;
        update(l, r, v);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE && dfs(i)) {
            cout << "TAK\n";
            return 0;
        }
    }

    cout << "NIE\n";
    return 0;
}
