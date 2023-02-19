#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int maxN = 5e5;

vector<int> adj[maxN + 1];
int n, m;
bool visited[maxN + 1];
vector<int> marchroute;

void dfs(int cur) {
    visited[cur] = true;
    marchroute.push_back(cur);
    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next);
            marchroute.push_back(cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1;; i++) {
        int v = marchroute[i];
        marchroute.push_back(v);
        if (v == n) {
            break;
        }
    }

    cout << marchroute.size() << endl;
    for (int v : marchroute) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
