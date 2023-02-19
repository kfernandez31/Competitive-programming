#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

long long cost[maxN + 1];
vector<int> graph[maxN + 1];
int deg[maxN + 1];
priority_queue<pair<long long, int>> minheap;
int n, m, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        deg[a]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            minheap.push({-1 * cost[i], i});
        }
    }

    long long res = LONG_LONG_MIN;
    while (k--) {
        auto [vcost, v] = minheap.top();
        minheap.pop();
    
        res = max(res, -1 * vcost);

        for (int nbor : graph[v]) {
            deg[nbor]--;
            if (deg[nbor] == 0) {
                minheap.push({-1 * cost[nbor], nbor});
            }
        }
    }

    cout << res << "\n";

    return 0;
}
