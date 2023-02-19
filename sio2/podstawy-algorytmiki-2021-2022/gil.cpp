#include <bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1e5, maxM = 5 * 1e5;
int n, m;
vector<int> graph[maxN + 1];
char label[maxN + 1];

void dfs(int v, bool k) {
    label[v] = k? 'K' : 'S';
    for (int w : graph[v]) {
        if (!label[w]) {
            dfs(w, 1 - k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool res = true;
    for (int i = 1; i <= n; i++) {
        if (graph[i].empty()) {
            res = false;
            break;
        }
    }

    if (!res) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n";

        for (int i = 1; i <= n; i++) {
            if (!label[i]) {
                dfs(i, 0);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << label[i] << "\n";
        }
    }
    return 0;
}
