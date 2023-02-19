#include <bits/stdc++.h>
using namespace std;

const int maxN = 5 * 1e5;
int n;
vector<int> graph[maxN];
bool visited[maxN];
int pre[maxN], maxPre[maxN];
int preTime = 1;

void dfs_rec(int cur) {
    int mp = preTime;
    pre[cur] = preTime;
    preTime++;

    visited[cur] = true;
    for (auto next : graph[cur]) {
        if (!visited[next]) {
            dfs_rec(next);
            mp = max(mp, preTime);
        }
    }
    
    maxPre[cur] = mp;
}

static inline bool is_superior(int a, int b) {
    return (pre[a] < pre[b] && maxPre[a] > pre[b]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int superior;
        cin >> superior;
        graph[superior].push_back(i);
    }

    dfs_rec(0);
    
    int a, b;
    for (;;) {
        cin >> a;
        if (a == -1)
            break;
        cin >> b;
        cout << (is_superior(a, b)? "TAK" : "NIE") << "\n";
    }

    return 0;
}
